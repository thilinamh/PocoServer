//
// Created by user on 12/18/15.
//

#ifndef POCOSERVER_INITALSTATE_H
#define POCOSERVER_INITALSTATE_H

#include "State.h"
#include "Singeleton.h"
class InitalState: public Singeleton<InitalState>, public State {

public:
    void processRequest(const std::string &data, User &context) override;



private:
    friend class Singeleton;

    InitalState() : Singeleton(), State() {
        std::cout<<"InitialState created"<<endl;
    }



private:
    InitalState(const InitalState& src);
    InitalState& operator=(const InitalState& rhs);

};


#endif //POCOSERVER_INITALSTATE_H
