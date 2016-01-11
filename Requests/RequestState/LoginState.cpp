//
// Created by tm on 11/01/16.
//

#include "LoginState.h"
#include "InitalState.h"
#include "../../UserStructure/User.hxx"
void LoginState::processRequest(const std::string &data, User &context) {
string uid =data.substr(0,4);
    cout<<"loading uid : "<<uid<<endl;
    context.setUid(uid);
    context.load();
    context.setCurrent_state(InitalState::getInstance());

}
