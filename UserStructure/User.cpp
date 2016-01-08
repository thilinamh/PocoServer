/* 
 * File:   User.cpp
 * Author: user
 * 
 * Created on December 11, 2015, 5:12 PM
 */

#include "User.hxx"
#include "iostream"
#include "../DBconnection.h"
#include <odb/transaction.hxx>
#include "User-odb.hxx"
#include "../Requests/RequestState/InitalState.h"
#include "../Requests/RequestState/RegistrationState.h"
#include "../Requests/Behaviours/Community/BehaviourContainerCOMM.h"

using namespace std;

User::User(const StreamSocket &socket) {

    current_state=&InitalState::getInstance();
    tcpConnection = new ServerConnection(socket);
    cout << "user created" << endl;
}

User::User(const User &orig) {

}

User::~User() {
    cout << "User deleted" << endl;
}

ServerConnection &User::getServerConnection() const {

    return *tcpConnection;
}

void User::bindWithServer() {
    // Before calling shared_from_this(),
    // there should be at least one std::shared_ptr p that owns *this
    tcpConnection->setContext(shared_from_this());
}


const string & User::getUid() const {
    return this->uid_;
}

void User::setUid(string uid) {
    this->uid_ = uid;

}

const string &User::getUuid() const {
    return this->uuid;


}

void User::setUuid(const string &uuid) {
    this->uuid = uuid;
}

User::User() {

}

void User::save() {
    odb::database& db = DBconnection::getDb();
    //delete &db;
    odb::transaction t(db.begin());
    db.persist(this);
    t.commit();
}

void User::load() {
    odb::database& db = DBconnection::getDb();
    odb::transaction t(db.begin());

    //unique_ptr<User> jane(db->load<User>(uid_));
    db.load (uid_, *this);
    t.commit();

}

void User::process(const string& data) {
    this->current_state->processRequest(data,*this);
}
void User::setCurrent_state(State &state)  {
    this->current_state=&state;
}

BehaviourContainer &User::getBehaviours() {
    cout<<"In user get behaviour"<<endl;
    _behaviours.reset(new BehaviourContainerCOMM());
    return *_behaviours;
}
