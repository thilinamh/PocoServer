//
// Created by tm on 07/01/16.
//

#include "BehaviourContainer.h"
RegistrationBehavior& BehaviourContainer:: getRegistrationBehaviour() const {
    return *regBehaviour;
}