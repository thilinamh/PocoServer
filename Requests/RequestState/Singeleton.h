//
// Created by tm on 06/01/16.
//

#ifndef POCOSERVER_SINGELETON_H
#define POCOSERVER_SINGELETON_H
#include <memory>
#include "State.h"
using namespace std;
template <typename T>
class Singeleton{

public:
    static T& getInstance(){
        if(_instance.get()== nullptr){
            _instance.reset(new T());
        }
        return *_instance;
    }

protected:
    Singeleton() { }
private:
    
    Singeleton(const Singeleton& src);
    Singeleton& operator=(const Singeleton& lhs);
    static unique_ptr<T> _instance;

};
template <typename T>
unique_ptr<T> Singeleton<T>::_instance;

#endif //POCOSERVER_SINGELETON_H
