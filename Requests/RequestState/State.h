//
// Created by user on 12/18/15.
//

#ifndef POCOSERVER_STATE_H
#define POCOSERVER_STATE_H

class State{

public:
    State() { }

    virtual void processRequest(char* data)=0;

};
#endif //POCOSERVER_STATE_H
