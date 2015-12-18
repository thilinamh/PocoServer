//
// Created by user on 12/18/15.
//

#ifndef POCOSERVER_INITALSTATE_H
#define POCOSERVER_INITALSTATE_H

#include "State.h"

class InitalState: public State {

public:
    void processRequest(char *data) override;
};


#endif //POCOSERVER_INITALSTATE_H
