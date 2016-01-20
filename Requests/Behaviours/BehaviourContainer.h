//
// Created by tm on 07/01/16.
//

#ifndef POCOSERVER_BEHAVIOURCONTAINER_H
#define POCOSERVER_BEHAVIOURCONTAINER_H


#include "RegistrationBehavior.h"
#include "VerificationBehaviour.h"

class BehaviourContainer {

public:
    virtual RegistrationBehavior& getRegistrationBehaviour() =0;
    virtual VerificationBehaviour& getVerificationBehaviour() =0;

protected:
    RegistrationBehavior* regBehaviour;
    VerificationBehaviour* verificationBehaviour;
};


#endif //POCOSERVER_BEHAVIOURCONTAINER_H
