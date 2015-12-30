/* 
 * File:   User.cpp
 * Author: user
 * 
 * Created on December 11, 2015, 5:12 PM
 */

#include "User.hxx"
#include "iostream"
using namespace std;

User::User(const StreamSocket& socket) {
    tcpConnection = new ServerConnection(socket);
    cout<<"user created"<<endl;
}

User::User(const User& orig) {

}

User::~User() {
    cout<<"User deleted"<<endl;
}

ServerConnection&  User::getServerConnection() const {

        return *tcpConnection;
 }

void User::bindWithServer() {
    // Before calling shared_from_this(),
    // there should be at least one std::shared_ptr p that owns *this
    tcpConnection->setContext(shared_from_this());
}


const string& User::getUid() const {
    return this->uid;
}

void User::setUid(const string &uid) {
    this->uid = uid;

}

const string& User::getUuid() const {
    return this->uuid;
}

void User::setUuid(const string &uuid) {
    this->uuid=uuid;
}

User::User() {

}
