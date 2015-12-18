//
// Created by user on 12/18/15.
//

#ifndef POCOSERVER_REGISTRATIONSTATE_H
#define POCOSERVER_REGISTRATIONSTATE_H

#include "State.h"

class RegistrationState :public State{

public:
    virtual void processRequest() override;
};


#endif //POCOSERVER_REGISTRATIONSTATE_H
