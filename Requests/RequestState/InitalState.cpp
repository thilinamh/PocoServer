//
// Created by user on 12/18/15.
//


#include "InitalState.h"
#include "../../UserStructure/User.hxx"
#include "RegistrationState.h"
#include "LoginState.h"
#include "../../Helper/Crypto.h"
#include "../../Helper/StringHelper.h"

__USING_NAMESPACE_STD()
void InitalState::processRequest(const std::string &data, User &context) {
    std::cout<<"in InitialState "<<std::endl;
    if (data.compare(0,3,"rrq")==0){
        cout<<"reg req"<<endl;
        context.setCurrent_state(RegistrationState::getInstance());
        throw std::invalid_argument("forwaded to registration");

    }else if(data.compare(0,3,"uid")==0){
        cout<<"Login req"<<endl;
        context.setCurrent_state(LoginState::getInstance());
        throw std::invalid_argument("forwaded to login");
    }else if(data.compare(0,3,"sht")==0){
        cout<<"Shutdown req"<<endl;
        context.closeSocket();
    }else{

    if(data.compare(0,3,"rfy")==0) {
        cout << "Verify req" << endl;
        string encrypted = data.substr(4); //take data part
        unique_ptr<string> decodedStr = Crypto::decryptRequest(&encrypted[0]);
        auto elements = StringHelper::split(*decodedStr, ',');

        shared_ptr<User> usr;

        string uid=(*elements)[0];
        for (auto usr:*(RegistrationState::getInstance().waitQue)){
            if(usr->getUid().compare(uid)==0){
                usr->renewServerConnection(context.getServerConnection()); // renew old users connectio
                context.getServerConnection()->setContext(usr); // renew server connection's context
                break;
            }
        }
        throw std::invalid_argument("socket renewed");
    }else{
        cerr<<"invalid request"<<endl;

    }


    }

}


