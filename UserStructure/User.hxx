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
#include "../Requests/Behaviours/BehaviourContainer.h"

using Poco::Net::StreamSocket;
using namespace std;


class ServerConnection;


class User: public enable_shared_from_this<User> {
public:
    User(const StreamSocket &socket, BehaviourContainer *behaviourContainer);
    User(const User& orig);
    virtual ~User(); // essential for polymorphic behaviour
    /**
     * tcpConnection will be given the current User object
     * */
    virtual void bindWithServer();

    ServerConnection& getServerConnection() const;

    const string & getUid() const;

    void setUid(const string &uid);

    const string &getUuid() const;

    void setUuid(const string &uuid);

    virtual bool save();
    virtual bool load_by_uid();
    virtual bool load_by_uuid(const string &uuid);
    void process(const std::string& );
    void setCurrent_state(State &state) ;
    virtual BehaviourContainer & getBehaviours();

protected:
    unique_ptr<BehaviourContainer> _behaviours;
    ServerConnection* tcpConnection; //do not own the object
    User(); //reserved for odb

private:
    friend  class odb::access;

    std::string uid_;

    std::string uuid;

    State* current_state; //do not own the object

};
#pragma db object(User) polymorphic
#pragma db member(User::uid_) id
#pragma db member(User::uuid) not_null
#pragma db member(User::regBehaviour) transient
#pragma db member(User::tcpConnection) transient
#pragma db member(User::request) transient
#pragma db member(User::state) transient
// odb --std c++11 -d mysql --generate-query --schema-format embedded  --generate-schema User.hxx
#endif	/* USER_H */

