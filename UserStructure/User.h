/* 
 * File:   User.h
 * Author: user
 *
 * Created on December 11, 2015, 5:12 PM
 */

#ifndef USER_H
#define	USER_H
#include <string>
#include "../ServerConnection.h"
#include "Poco/Net/StreamSocket.h"
#include "../Requests/RequestInterface.h"
#include "../Requests/RequestState/State.h"
#include "../Requests/Behaviours/RegistrationBehavior.h"

using Poco::Net::StreamSocket;
using std::string;

class ServerConnection;


class User {
public:
    User(const StreamSocket& socket);
    User(const User& orig);
    virtual ~User();

    ServerConnection & GetTcpConnection() const;

protected:
    RegistrationBehavior* regBehaviour;

private:
    ServerConnection* tcpConnection;
    string uid;
    string uuid;
    RequestInterface* request;
    State* state;

};

#endif	/* USER_H */

