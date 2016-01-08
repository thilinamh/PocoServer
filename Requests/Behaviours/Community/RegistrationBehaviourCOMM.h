//
// Created by user on 12/21/15.
//

#ifndef POCOSERVER_REGISTRATIONBEHAVIOURCOMMUNITY_H
#define POCOSERVER_REGISTRATIONBEHAVIOURCOMMUNITY_H

#include "../RegistrationBehavior.h"
#include "../../../Helper/Singleton.h"

class RegistrationBehaviourCOMM :public Singleton<RegistrationBehaviourCOMM>,public  RegistrationBehavior{

public:
    bool registerUser(const string &uid, const string &uuid, const string &additional) override;
private:
    friend class Singleton;
    RegistrationBehaviourCOMM() : Singleton() {cout<<"RegBehaviourCOMM obj created"<<endl; }
};


#endif //POCOSERVER_REGISTRATIONBEHAVIOURCOMMUNITY_H
