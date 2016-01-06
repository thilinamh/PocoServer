//
// Created by user on 12/18/15.
//

#ifndef POCOSERVER_INITALSTATE_H
#define POCOSERVER_INITALSTATE_H

#include "State.h"

class InitalState: public State {

public:
    void processRequest(const std::string &data, User &context) override;

    virtual State &getInstance() override;

private:
    InitalState(){};
    InitalState(const InitalState& src);
    InitalState& operator=(const InitalState& rhs);

};


#endif //POCOSERVER_INITALSTATE_H
