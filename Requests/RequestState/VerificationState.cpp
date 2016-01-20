//
// Created by user on 12/18/15.
//
#define REG_OK "rgk\r\n"
#define REG_ERROR "rge\r\n"

#include "VerificationState.h"
#include "../Behaviours/VerificationBehaviour.h"
#include "../../Helper/Crypto.h"
#include "../../Helper/StringHelper.h"
#include "../../UserStructure/User.hxx"
#include "../RequestState/InitalState.h"

void VerificationState::processRequest(const std::string &data, User &context) {

    std::cout << "in Verification " << data << std::endl;

    if (data.compare(0, 3, "rfy") == 0) {
        string encrypted = data.substr(4); //take data part
        unique_ptr<string> decodedStr = Crypto::decryptRequest(&encrypted[0]);
        auto elements = StringHelper::split(*decodedStr, ',');

        for (string x:*elements) {
            cout << x << endl;
        }
        string uid=(*elements)[0];
        string verif_num=(*elements)[1];
        if(context.getUid().compare(uid)==0){
            bool success=context.verifyRegistration(verif_num);
            if(success){
                context.writeToClient(REG_OK);
                context.setCurrent_state(InitalState::getInstance());
            }
        } else{
            cout<<"verification error"<<endl;
            context.writeToClient(REG_ERROR);
        }

    } else{
        context.setCurrent_state(InitalState::getInstance());
        throw std::invalid_argument("forwaded to initial state");
    }
}
