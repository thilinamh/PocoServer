//
// Created by user on 12/21/15.
//

#ifndef POCOSERVER_VERIFICATIONBEHAVIOURCOMMUNITY_H
#define POCOSERVER_VERIFICATIONBEHAVIOURCOMMUNITY_H


#include "../../../Helper/Singleton.h"

class VerificationBehaviourCOMM :public Singleton<VerificationBehaviourCOMM> {

private:friend class Singleton;
    VerificationBehaviourCOMM() : Singleton() { cout<<"VerifBehaviourCOMM obj created"<<endl;}
};


#endif //POCOSERVER_VERIFICATIONBEHAVIOURCOMMUNITY_H
