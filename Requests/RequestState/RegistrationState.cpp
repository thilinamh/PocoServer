//
// Created by user on 12/18/15.
//
#define REG_ERROR "rge\r\n"
#define REG_PENDING "rpd\r\n"

#include "RegistrationState.h"
#include "../../UserStructure/User.hxx"
#include "../RequestState/InitalState.h"
#include "../../Helper/Crypto.h"
#include "../../Helper/StringHelper.h"
#include "VerificationState.h"

void RegistrationState::processRequest(const std::string &data, User &context) {
    std::cout << "in Registration " << data << std::endl;

    if (data.compare(0, 3, "rrq") == 0) {

        string encrypted = data.substr(4); //take data part
        try {
            /*BehaviourContainer* a= &context.getBehaviours();
            if(a== nullptr){
                cout<<"null"<<endl;
            }*/
            //string uid=data.substr(0,4);
            //string uuid=data.substr(5,8);
            unique_ptr<string> decodedStr = Crypto::decryptRequest(&encrypted[0]);


            auto elements = StringHelper::split(*decodedStr, ',');

            for (string x:*elements) {
                cout << x << endl;
            }
            context.setUid((*elements)[0]);
            context.setUuid((*elements)[2]);

            if (context.registerUser((*elements)[1])) {
                context.writeToClient(REG_PENDING);
                context.setCurrent_state(VerificationState::getInstance());

            } else {
                context.writeToClient(REG_ERROR);
                context.setCurrent_state(InitalState::getInstance());

            }

            //context.save();
        } catch (std::bad_exception &e) {
            cout << e.what() << endl;
        } catch (std::invalid_argument &e) {
            cout << e.what() << endl;
        } catch (...) {
            cout << "error Registering" << endl;
        }
    } else {
        context.setCurrent_state(InitalState::getInstance());
        throw std::invalid_argument("forwaded to initial state");
    }
}

