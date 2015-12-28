/* 
 * File:   TCPClientConnectionFactory.cpp
 * Author: user
 * 
 * Created on December 11, 2015, 5:22 PM
 */
#include <memory>
#include "TCPClientConnectionFactory.h"
#include "UserStructure/User.hxx"

//#include "ServerConnection.h"
ClientConnectionFactory::ClientConnectionFactory() {
}

ClientConnectionFactory::ClientConnectionFactory(const ClientConnectionFactory& orig) {
}

ClientConnectionFactory::~ClientConnectionFactory() {
}

TCPServerConnection*  ClientConnectionFactory::createConnection(const StreamSocket& socket){
   shared_ptr<User> usr (new User(socket));
   usr->bindWithServer();

   return dynamic_cast<TCPServerConnection*>(&(usr->getServerConnection()));
}

