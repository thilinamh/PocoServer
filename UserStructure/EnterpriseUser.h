//
// Created by user on 12/21/15.
//

#ifndef POCOSERVER_ENTERPRISEUSER_H
#define POCOSERVER_ENTERPRISEUSER_H

#include "User.hxx"
#include "../Requests/Behaviours/RegistrationBehavior.h"
#include "../Requests/Behaviours/ConferenceBehaviourEnterprise.h"

class EnterpriseUser : public User{

public:
    EnterpriseUser(const StreamSocket &socket) : User(socket) { }

private:
    ConferenceBehaviourEnterprise* confBehaviour;
};


#endif //POCOSERVER_ENTERPRISEUSER_H
