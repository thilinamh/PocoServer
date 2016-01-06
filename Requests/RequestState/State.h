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

    template <typename T>
    void load ( T& object);
    virtual void processRequest(const std::string &data, User &context) =0;
     static State& getInstance()=0;
    virtual ~State();

protected:
    static std::unique_ptr<State> _instance;
    State() { }

private:
    State(const State& src);
    State& operator=(const State& rhs);
};
#endif //POCOSERVER_STATE_H
