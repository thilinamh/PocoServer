//
// Created by user on 12/18/15.
//

#ifndef POCOSERVER_REGISTRATIONSTATE_H
#define POCOSERVER_REGISTRATIONSTATE_H

#include "State.h"
#include "../Behaviours/RegistrationBehavior.h"

class RegistrationState :public State{

public:

    virtual void processRequest(const std::string &data, User &context) override;

    //static State & getInstance() override;



private:
    RegistrationState(){};
    RegistrationState(const RegistrationState& src);
    RegistrationState& operator=(const RegistrationState& rhs);

private:
    RegistrationBehavior* behavior; // enterprise or community
};


#endif //POCOSERVER_REGISTRATIONSTATE_H
