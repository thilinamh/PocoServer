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

using Poco::Net::StreamSocket;
using std::string;

class ServerConnection;


class User {
public:
    User(const StreamSocket& socket);
    User(const User& orig);
    virtual ~User();

    ServerConnection & GetTcpConnection() const;

private:
    ServerConnection* tcpConnection;
    string uid;
    string uuid;
    RequestInterface* request;

};

#endif	/* USER_H */

