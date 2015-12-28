/* 
 * File:   User.h
 * Author: user
 *
 * Created on December 11, 2015, 5:12 PM
 */

#ifndef USER_H
#define	USER_H
#include <string>
#include <tr1/memory>
#include <odb/core.hxx>
#include "../ServerConnection.h"
#include "Poco/Net/StreamSocket.h"
#include "../Requests/RequestInterface.h"
#include "../Requests/RequestState/State.h"
#include "../Requests/Behaviours/RegistrationBehavior.h"

using Poco::Net::StreamSocket;
using namespace std::tr1;


class ServerConnection;


class User: public enable_shared_from_this<User> {
public:
    User(const StreamSocket& socket);
    User(const User& orig);
    virtual ~User(); // essential for polymorphic behaviour
    /**
     * tcpConnection will be given the current User object
     * */
    void bindWithServer();
    ServerConnection& getServerConnection() const;
    //virtual RegistrationBehavior* getRegBehaviour() const;

    const std::string &getUid() const;

    void setUid(const std::string &uid);

    const std::string &getUuid() const;

    void setUuid(const std::string &uuid);

protected:
    RegistrationBehavior* regBehaviour;

private:
    friend  class odb::access;
    User();

    ServerConnection* tcpConnection;

    std::string uid;

    std::string uuid;

    RequestInterface* request;

    State* state;



};
#pragma db object(User) polymorphic
#pragma db member(User::uid) id not_null
#pragma db member(User::uuid) not_null
#pragma db member(User::regBehaviour) transient
#pragma db member(User::tcpConnection) transient
#pragma db member(User::request) transient
#pragma db member(User::state) transient

#endif	/* USER_H */

