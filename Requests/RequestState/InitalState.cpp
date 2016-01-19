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
    if (data.compare(0,3,"rrq")==0){
        cout<<"reg req"<<endl;
        context.setCurrent_state(RegistrationState::getInstance());
        throw std::invalid_argument("forwaded to registration");

    }else if(data.compare(0,3,"uid")==0){
        cout<<"Login req"<<endl;
        context.setCurrent_state(LoginState::getInstance());
        throw std::invalid_argument("forwaded to login");

    }else{
        cerr<<"invalid request"<<endl;
    }

}


