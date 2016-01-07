//
// Created by tm on 06/01/16.
//

#ifndef POCOSERVER_SINGELETON_H
#define POCOSERVER_SINGELETON_H
#include <memory>
#include "../Requests/RequestState/State.h"
using namespace std;
template <typename T>
class Singleton {

public:
    static T& getInstance();

protected:
    Singleton() { }
private:
    
    Singleton(const Singleton & src);
    Singleton & operator=(const Singleton & lhs);
    static unique_ptr<T> _instance;

};
template <typename T>
unique_ptr<T> Singleton<T>::_instance;

template <typename T>
T& Singleton<T>::getInstance(){
    if(_instance.get()== nullptr){
        _instance.reset(new T());
    }
    return *_instance;
}
#endif //POCOSERVER_SINGELETON_H
