//
// Created by user on 12/16/15.
//

#ifndef POCOSERVER_REGRQUEST_H
#define POCOSERVER_REGRQUEST_H

#include "RequestInterface.h"

class RegistrationBehavior : public RequestInterface {

public:
    bool processReques() override;
    bool registerUser();
};


#endif //POCOSERVER_REGRQUEST_H
