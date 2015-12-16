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
    tcpConnection->setContext(this);
}

User::User(const User& orig) {
}

User::~User() {
    cout<<"User deleted"<<endl;
}

ServerConnection &  User::GetTcpConnection() const {
        return *tcpConnection;
 }

