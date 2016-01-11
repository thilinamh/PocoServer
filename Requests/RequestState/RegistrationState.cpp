//
// Created by user on 12/18/15.
//

#include "RegistrationState.h"
#include "../../UserStructure/User.hxx"
#include "../RequestState/InitalState.h"
void RegistrationState::processRequest(const std::string &data, User &context) {
    std::cout<<"in Registration "<<data<<std::endl;
    if (data[0]=='i'){
        context.setCurrent_state(InitalState::getInstance());
        return;
    }
    try {
        BehaviourContainer* a= &context.getBehaviours();
        if(a== nullptr){
            cout<<"null"<<endl;
        }
        string uid=data.substr(0,4);
        string uuid=data.substr(5,8);
        a->getRegistrationBehaviour().registerUser(uid,uuid);

        context.setUid(uid);
        context.setUuid(uuid);
        context.save();
    }catch (...){
        cout<<"error saving"<<endl;
    }

}

