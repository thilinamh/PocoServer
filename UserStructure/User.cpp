/* 
 * File:   User.cpp
 * Author: user
 * 
 * Created on December 11, 2015, 5:12 PM
 */

#include "User.h"
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

ServerConnection &  User::getServerConnection() const {

        return *tcpConnection;
 }

void User::bindWithServer() {
    // Before calling shared_from_this(),
    // there should be at least one std::shared_ptr p that owns *this
    tcpConnection->setContext(shared_from_this());
}
