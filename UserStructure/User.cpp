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
#include "../Requests/Behaviours/Community/BehaviourContainerCOMM.h"
#include <odb/query.hxx>

using namespace std;

User::User(const StreamSocket &socket, BehaviourContainer *behaviourContainer): _behaviours(behaviourContainer) {

    current_state=&InitalState::getInstance();
    tcpConnection = new ServerConnection(socket);
    cout << "user created" << endl;
}

User::User(const User &orig)  {

}

User::User()  {

}

User::~User() {
    cout << "User deleted" << endl;
}

ServerConnection * User::getServerConnection() const {

    return tcpConnection;
}

void User::bindWithServer() {
    // Before calling shared_from_this(),
    // there should be at least one std::shared_ptr p that owns *this
    tcpConnection->setContext(shared_from_this());
}


const string & User::getUid() const {
    return this->uid_;
}

void User::setUid(const string &uid) {
    this->uid_ = uid;

}

const string &User::getUuid() const {
    return this->uuid;
}

void User::setUuid(const string &uuid) {
    this->uuid = uuid;
}

bool User::save() {
    odb::database& db = DBconnection::getDb();
    //delete &db;
    odb::transaction t(db.begin());
    try {
        db.persist(*this);
        t.commit();
        cout<<"user saved"<<endl;
    }catch (const odb::object_already_persistent& e){
        cout<<"user already exist"<<endl;
        return false;
    }
    return true;

}

bool User::load_by_uid() {
    odb::database& db = DBconnection::getDb();
    odb::transaction t(db.begin());

    //unique_ptr<User> jane(db->load<User>(uid_));
    try{
        db.load (uid_, *this);
        t.commit();
        cout<<"user loaded sucessfully "<<" uuid : "<<this->uuid<<endl;
    }catch(const odb::object_not_persistent& e){
        cout<<"user does not exist"<<endl;
        t.rollback();
        return false;
    }
    return true;

}

bool User::load_by_uuid(const string &uuid) {
    odb::database& db = DBconnection::getDb();
    odb::transaction t(db.begin());

    typedef odb::query<User> query;
    typedef odb::result<User> result;

    //query q (query::uuid == query::_ref (this->uuid));
    bool a=db.query_one<User> (query::uuid==query::_ref(uuid), *this);
    t.commit();
    return a;

}

void User::process(const string& data) {
    this->current_state->processRequest(data,*this);
}
void User::setCurrent_state(State &state)  {
    this->current_state=&state;
}
/*
BehaviourContainer &User::getBehaviours() {
    cout<<"In user get behaviour"<<endl;
    _behaviours.reset(new BehaviourContainerCOMM());
    return *_behaviours;
}
*/

bool User::registerUser(const string &decrpted_data) {
   return this->_behaviours->getRegistrationBehaviour().registerUser(uid_, uuid, decrpted_data);
}

bool User::verifyRegistration(const string & verification_num) {
    return this->_behaviours->getVerificationBehaviour().verify(verification_num,this->uuid);
}


int User::writeToClient(const string &command) {
    this->tcpConnection->writeToSocket(command);
}

void User::closeSocket() {
    this->tcpConnection->closeSocketConnection();
}

void User::renewServerConnection(ServerConnection *tcpCon) {
    //this->tcpConnection->closeSocketConnection();
    this->tcpConnection=tcpCon;
}
