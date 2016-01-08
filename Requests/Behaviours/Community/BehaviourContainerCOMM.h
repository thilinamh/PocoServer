//
// Created by tm on 07/01/16.
//

#ifndef POCOSERVER_BEHAVIOURCONTAINERCOMM_H
#define POCOSERVER_BEHAVIOURCONTAINERCOMM_H


#include "../BehaviourContainer.h"
#include "RegistrationBehaviourCOMM.h"
#include "VerificationBehaviourCOMM.h"

class BehaviourContainerCOMM:public BehaviourContainer {

public:
    virtual RegistrationBehavior &getRegistrationBehaviour()  override;

private:
    RegistrationBehaviourCOMM* regBehaviour;
    VerificationBehaviourCOMM* verfyBehaviour;
};


#endif //POCOSERVER_BEHAVIOURCONTAINERCOMM_H
