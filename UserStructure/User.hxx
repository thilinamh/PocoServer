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
#include <odb/core.hxx>
#include "../ServerConnection.h"
#include "Poco/Net/StreamSocket.h"
#include "../Requests/RequestInterface.h"
#include "../Requests/RequestState/State.h"
#include "../Requests/Behaviours/RegistrationBehavior.h"

using Poco::Net::StreamSocket;
using namespace std;


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

    const string & getUid() const;

    void setUid(string uid);

    const string &getUuid() const;

    void setUuid(const string &uuid);

    void save();
    void load();
    void process(const std::string& );
    void setCurrent_state(State &state) ;

protected:
    RegistrationBehavior* regBehaviour;

private:
    friend  class odb::access;
    User();

    ServerConnection* tcpConnection;

    std::string uid_;

    std::string uuid;

    RequestInterface* request;

    State* current_state;



};
#pragma db object(User)
 //polymorphic
#pragma db member(User::uid_) id
#pragma db member(User::uuid) not_null
#pragma db member(User::regBehaviour) transient
#pragma db member(User::tcpConnection) transient
#pragma db member(User::request) transient
#pragma db member(User::state) transient
// odb --std c++11 -d mysql --generate-query --schema-format embedded  --generate-schema User.hxx
#endif	/* USER_H */

