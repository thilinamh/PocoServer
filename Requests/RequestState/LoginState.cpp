//
// Created by tm on 11/01/16.
//

#include "LoginState.h"
#include "InitalState.h"
#include "../../UserStructure/User.hxx"
void LoginState::processRequest(const std::string &data, User &context) {
    if(data[0]=='i'){
        context.setCurrent_state(InitalState::getInstance());
        return;
    }
    string uid =data.substr(0,4);
    cout<<"loading uid : "<<uid<<endl;
    context.setUid(uid);
    bool found=context.load_by_uid();
    string uuid= data.substr(5,8);
    if(!found){

        bool loaded=context.load_by_uuid(uuid);
        cout<<"loaded by uuid : "<<loaded<<" uid->"<<context.getUid()<<endl;
    }


}
