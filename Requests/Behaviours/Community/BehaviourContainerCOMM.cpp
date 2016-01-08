//
// Created by tm on 07/01/16.
//

#include "BehaviourContainerCOMM.h"

RegistrationBehavior &BehaviourContainerCOMM::getRegistrationBehaviour()  {
    if(regBehaviour== nullptr){
        regBehaviour=&RegistrationBehaviourCOMM::getInstance();
    }
    return *regBehaviour;
}
