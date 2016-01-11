//
// Created by tm on 07/01/16.
//

#include "BehaviourContainerENT.h"

RegistrationBehavior &BehaviourContainerENT::getRegistrationBehaviour() {
 if(regBehaviour== nullptr){
  regBehaviour=&RegistrationBehaviourENT::getInstance();
 }
 return *regBehaviour;
}
