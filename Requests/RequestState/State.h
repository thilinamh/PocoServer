//
// Created by user on 12/18/15.
//

#ifndef POCOSERVER_STATE_H
#define POCOSERVER_STATE_H
#include <odb/core.hxx>
class State{

public:
    State() { }
    template <typename T>
    void load ( T& object);
    virtual void processRequest(char* data)=0;

};
#endif //POCOSERVER_STATE_H
