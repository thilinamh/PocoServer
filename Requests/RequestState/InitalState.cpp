//
// Created by user on 12/18/15.
//


#include "InitalState.h"
#include "../../UserStructure/User.hxx"
#include "RegistrationState.h"
#include "LoginState.h"

__USING_NAMESPACE_STD()
void InitalState::processRequest(const std::string &data, User &context) {
    std::cout<<"in InitialState "<<std::endl;
    if (data[0]=='r'){
        cout<<"reg req"<<endl;
        context.setCurrent_state(RegistrationState::getInstance());
    }else if(data[0]=='l'){
        cout<<"Login req"<<endl;
        context.setCurrent_state(LoginState::getInstance());
    }

}


