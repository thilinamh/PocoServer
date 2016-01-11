//
// Created by tm on 11/01/16.
//

#ifndef POCOSERVER_LOGINSTATE_H
#define POCOSERVER_LOGINSTATE_H

#include "../../Helper/Singleton.h"

class LoginState :public State, public Singleton<LoginState>{

public:
     void processRequest(const std::string &data, User &context) override final;
};


#endif //POCOSERVER_LOGINSTATE_H
