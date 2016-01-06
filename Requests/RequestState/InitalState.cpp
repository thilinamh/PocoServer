//
// Created by user on 12/18/15.
//


#include "InitalState.h"
#include "../../UserStructure/User.hxx"
#include "RegistrationState.h"
__USING_NAMESPACE_STD()
void InitalState::processRequest(const std::string &data, User &context) {
    std::cout<<data<<std::endl;
    if (data.find('r',0)){
        context.setCurrent_state(RegistrationState::getInstance());
    }
    std::is_c

}

State &InitalState::getInstance() {
    if(_instance.get()== nullptr){
        _instance.reset(new InitalState);
    }
    return *_instance;
}
