//
// Created by user on 12/18/15.
//

#include "RegistrationState.h"
#include "../../UserStructure/User.hxx"
#include "../RequestState/InitalState.h"
void RegistrationState::processRequest(const std::string &data, User &context) {
    std::cout<<"in Registration"<<data<<std::endl;
    if (data[0]=='i'){
        context.setCurrent_state(InitalState::getInstance());
    }
}



