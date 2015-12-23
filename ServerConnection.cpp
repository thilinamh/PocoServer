/* 
 * File:   TCPconnection.cpp
 * Author: user
 * 
 * Created on December 9, 2015, 12:31 PM
 */

#include "ServerConnection.h"
#include "UserStructure/User.h"
#include "ClientRequest.h"
#include <iostream>
#include <Poco/BufferedStreamBuf.h>
using Poco::BufferedStreamBuf;
using namespace std;

ServerConnection::ServerConnection(const StreamSocket& client) : TCPServerConnection(client) {
    std::cout << "Server connection constuctor"<<client.peerAddress().toString() << endl;
    
}
void ServerConnection::setContext(shared_ptr<User> context) {
    std::cout<<"user assigned"<<endl;
        this->context = context;
    // this assignement is valid until context is a shared_ptr;
    // if you receive a raw ptr, you need to use reset(raw_ptr) method

 }

/*ServerConnection::ServerConnection(const ServerConnection& orig) {
    std::cout<<"client connection constuctor 1"<<endl;
}*/

ServerConnection::~ServerConnection() {
    std::cout<<"ServerConnection distructor"<<endl;
}

void ServerConnection::setConnectionCheckParams(int idle_time, int ack_packets, int ack_interval){
        
    this->socket().setKeepAlive(true);
   
    this->socket().setOption(IPPROTO_TCP, TCP_KEEPIDLE,idle_time);
  
    this->socket().setOption(IPPROTO_TCP, TCP_KEEPCNT,ack_packets);

    this->socket().setOption(IPPROTO_TCP, TCP_KEEPINTVL,ack_interval);
}

void ServerConnection::run() {
    bool exit = false;
    setConnectionCheckParams(5,3,1); // if peer lost it's connection to the server, socket will close automatically
                                     // distructor will be called when closing the socket
    ClientRequest r;
    while (!exit) {
        const short BUF_SIZE = 2048;
        char buf[BUF_SIZE];
          
       // BufferedStreamBuf b(std::streamsize(5),OSin));
       
        int size = this->socket().receiveBytes(buf, BUF_SIZE-1);
        
        std::cout << "client connection "<< size<<" bytes " << endl;
        std::stringstream duf;
        //StringTokenizer.
        duf<<buf;
        std::cout << duf.str() << endl;
        //r.decodeRequest(duf);
        //char* decodedC = r.decodeRequest(&buf[4]);
        if (size==0) {
            //exit = true;
            this->socket().close();
            std::cout << "No data" << endl;
        }
        
        //int val=this->socket().sendBytes(reinterpret_cast<void*> (buf), BUF_SIZE-1);
        //if (val<0)
    }
    
}
