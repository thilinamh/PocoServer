//
// Created by user on 12/18/15.
//

#ifndef POCOSERVER_REGISTRATIONSTATE_H
#define POCOSERVER_REGISTRATIONSTATE_H

#include "State.h"
#include "../Behaviours/RegistrationBehavior.h"

class RegistrationState :public State{

public:

    virtual void processRequest(char *data) override;

private:
    RegistrationBehavior* behave; // enterprise or community
};


#endif //POCOSERVER_REGISTRATIONSTATE_H
