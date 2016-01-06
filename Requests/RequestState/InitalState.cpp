//
// Created by user on 12/18/15.
//


#include "InitalState.h"
#include "../../UserStructure/User.hxx"
#include "RegistrationState.h"
__USING_NAMESPACE_STD()
void InitalState::processRequest(const std::string &data, User &context) {
    std::cout<<"in InitialState"<<data<<std::endl;
    if (data[0]=='r'){
        cout<<"reg req"<<endl;
        context.setCurrent_state(RegistrationState::getInstance());
    }

}


