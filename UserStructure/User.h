/* 
 * File:   User.h
 * Author: user
 *
 * Created on December 11, 2015, 5:12 PM
 */

#ifndef USER_H
#define	USER_H
#include <string>
#include <memory>
#include "../ServerConnection.h"
#include "Poco/Net/StreamSocket.h"
#include "../Requests/RequestInterface.h"
#include "../Requests/RequestState/State.h"
#include "../Requests/Behaviours/RegistrationBehavior.h"

using Poco::Net::StreamSocket;
using namespace std;

class ServerConnection;

#pragma db object polymorphic
class User: public enable_shared_from_this<User> {
public:
    User(const StreamSocket& socket);
    User(const User& orig);
    virtual ~User(); // essential for polymorphic behaviour
    /**
     * tcpServerConnection will be given the current User object
     * */
    void bindWithServer();
    ServerConnection &getServerConnection() const;
    virtual RegistrationBehavior* getRegBehaviour() const;




protected:
    RegistrationBehavior* regBehaviour;

private:
    ServerConnection* tcpConnection;
    #pragma db id
    std::string uid;
    std::string uuid;
    RequestInterface* request;
    State* state;

};

#endif	/* USER_H */

