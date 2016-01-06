//
// Created by user on 12/18/15.
//

#ifndef POCOSERVER_REGISTRATIONSTATE_H
#define POCOSERVER_REGISTRATIONSTATE_H

#include "State.h"
#include "../Behaviours/RegistrationBehavior.h"
#include "../RequestState/Singeleton.h"

class RegistrationState :public State, public Singeleton<RegistrationState>{

public:

    virtual void processRequest(const std::string &data, User &context) override;




private:
    friend class Singeleton; // because we are invoking private ctor from template
    RegistrationState(){cout<<"RegistrationState created "<<endl;};
    RegistrationState(const RegistrationState& src);
    RegistrationState& operator=(const RegistrationState& rhs);

private:
    RegistrationBehavior* behavior; // enterprise or community
};


#endif //POCOSERVER_REGISTRATIONSTATE_H
