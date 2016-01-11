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
    //Derived objects should never be deleted by pointers of this type
    ~Singleton() {cout<<"Singleton Destructor"<<endl; }

private:
    
    Singleton(const Singleton & src);
    Singleton & operator=(const Singleton & lhs);
    static unique_ptr<T> _instance;

};
template <typename T>
unique_ptr<T> Singleton<T>::_instance;
/*we have to use Singleton<T>:: definition instead of Singleton:: when defining outside of the header
    even for ctor dtor
 */

template <typename T>
T& Singleton<T>::getInstance(){
    if(_instance.get()== nullptr){
        _instance.reset(new T());
    }
    return *_instance;
    //return _instance.get() ? *_instance : (_instance.reset( new T()));
}
#endif //POCOSERVER_SINGELETON_H
