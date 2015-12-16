/* 
 * File:   TCPClientConnectionFactory.cpp
 * Author: user
 * 
 * Created on December 11, 2015, 5:22 PM
 */

#include "TCPClientConnectionFactory.h"
#include "UserStructure/User.h"

//#include "ServerConnection.h"
ClientConnectionFactory::ClientConnectionFactory() {
}

ClientConnectionFactory::ClientConnectionFactory(const ClientConnectionFactory& orig) {
}

ClientConnectionFactory::~ClientConnectionFactory() {
}

TCPServerConnection*  ClientConnectionFactory::createConnection(const StreamSocket& socket){
   User* usr = new User(socket);
  
   return dynamic_cast<TCPServerConnection*>(&(usr->GetTcpConnection()));
}

