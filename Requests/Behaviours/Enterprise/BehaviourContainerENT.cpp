//
// Created by tm on 07/01/16.
//

#include "BehaviourContainerENT.h"
#include "VerificationBehaviourENT.h"

RegistrationBehavior &BehaviourContainerENT::getRegistrationBehaviour() {
 if(regBehaviour== nullptr){
  regBehaviour=&RegistrationBehaviourENT::getInstance();
 }
 return *regBehaviour;
}

VerificationBehaviour &BehaviourContainerENT::getVerificationBehaviour() {
 if(BehaviourContainer::verificationBehaviour== nullptr){
  BehaviourContainer::verificationBehaviour=&VerificationBehaviourENT::getInstance();
 }
 return *BehaviourContainer::verificationBehaviour;
}
