//
// Created by user on 12/18/15.
//

#ifndef POCOSERVER_STATE_H
#define POCOSERVER_STATE_H
#include <odb/core.hxx>
#include <memory>
#include <iostream>
class User;
class State{

public:

    virtual void processRequest(const std::string &data, User &context) =0;
    virtual ~State();

protected:
    State();

private:
    State(const State& src);
    State& operator=(const State& rhs);
};
#endif //POCOSERVER_STATE_H
