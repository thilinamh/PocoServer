//
// Created by user on 12/21/15.
//

#ifndef POCOSERVER_COMMUNITYUSER_H
#define POCOSERVER_COMMUNITYUSER_H

#include "User.h"
#include "../Requests/Behaviours/RegistrationBehavior.h"
#include "../Requests/Behaviours/VerificationBehaviourCommunity.h"

class CommunityUser: public User {

public:
    CommunityUser(const StreamSocket &socket) : User(socket) { }

private:
    VerificationBehaviourCommunity* verfBehaviour;
};


#endif //POCOSERVER_COMMUNITYUSER_H
