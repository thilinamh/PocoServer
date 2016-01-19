//
// Created by tm on 19/01/16.
//

#include <string.h>
#include "VerificationBehaviour.h"
#include "../../Helper/OTP/OTPAuthRequest.h"
using namespace std;
bool VerificationBehaviour::verify(const std::string &verification_num, const std::string &uuid) {
    char   java_cmd[1024]{}, pbuff[128]{}, tref[13]{}, _tmp[10]{};


    OTPAuthRequest ota;
    FILE *f;

    cout << "Verification..." << endl;

        cout << "Using OTP ... ";

        strncpy(_tmp, uuid.c_str(), 8);
        sprintf(tref, "%012li", strtol(_tmp, NULL, 16));

        ota.setAppType("IB");
        ota.setPassword("550a141f12de6341fba65b0ad0433500");
        ota.setMessageType("03");
        ota.setTransRefNo(tref);
        ota.setVerif(verification_num.c_str());
        cout << ota.getMessage() << endl;

        strcpy(java_cmd, "java -jar /home/tm/Desktop/Clion/ClionProjects/PocoServer/J/OTP.jar ");
        strcat(java_cmd, "\"");
        strcat(java_cmd, ota.getMessage());
        strcat(java_cmd, "\"");

        cout << "Executing Command pipe " << java_cmd << endl;

        f = popen(java_cmd, "r");

        if (!f) {
            cerr << "Command execution error !! " << endl;
            return false;
        }

        memset(pbuff, 0x00, 128);

        while (!feof(f)) {
            fgets(pbuff, 128, f);
        }
        pclose(f);

        cout << "OTP Result : " << pbuff << endl;

        if (strcmp(pbuff, "00") == 0x00) {
            return true;
        }

        return false;
}
