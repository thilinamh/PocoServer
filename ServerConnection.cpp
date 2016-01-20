/* 
 * File:   TCPconnection.cpp
 * Author: user
 * 
 * Created on December 9, 2015, 12:31 PM
 */

#include "ServerConnection.h"
#include "UserStructure/User.hxx"
#include "ClientRequest.h"
#include "Helper/Crypto.h"
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

void ServerConnection::setHeartbeatParams(int idle_time, int ack_packets, int ack_interval){
        
    this->socket().setKeepAlive(true);
   
    this->socket().setOption(IPPROTO_TCP, TCP_KEEPIDLE,idle_time);
  
    this->socket().setOption(IPPROTO_TCP, TCP_KEEPCNT,ack_packets);

    this->socket().setOption(IPPROTO_TCP, TCP_KEEPINTVL,ack_interval);
}

void ServerConnection::run() {
    bool exit = false;
    setHeartbeatParams(5, 3, 1); // if peer lost it's connection to the server, socket will close automatically
                                     // distructor will be called when closing the socket

    while (!exit) {

        const short BUF_SIZE = 2049;
        string buffer(BUF_SIZE,0);
       // BufferedStreamBuf b(std::streamsize(5),OSin));
       
        int bytesReceived = this->socket().receiveBytes(&buffer[0], BUF_SIZE-1);
        buffer.resize(bytesReceived);
        std::cout << bytesReceived <<" bytes received : " ;
        std::cout << buffer <<endl;

        {   /*
            std::stringstream duf;
            duf << buf;
            std::cout << duf.str() << endl;
            r.decryptRequest(duf);
            */
        }
        /*
         cEz2DFPoJr2UyWRRxptjas66mBw3UHnpBknMJ9bxB7Yx6Nm7lsnaSxs6RCAVJjzZrP7UKhFwpvBnJjzJ0WW8cuAMhzyEtFJppiUvdL6ZJWp8YqqJiXwucC8huaz5g0fAnS7CidhWq1Cv9WJP6jBVI5zrFUmzghSWLEVRp3yvMcs5qAxbsDhKr2S2xcfqNs/+RmpwJD1ACbLfH/bgMkQhSDk/gCkdLG+pbDb5Pp40Q0Vyge0mwjVR1m3DQfndCFJ8vR+qvUIZwFExNArEqhCvo5J/XfG33bffmH8vivS2C17nmOJ4yT14+GBKRi1b0xIp5gDRuBFOgqjB5zas+7Zuyg==
         Czr2v73+W5tDG38dDcAwAixlZl28w11BghNBSnShGjmDVuez472bb7Vcup9MK9ihhEM0Uq7T6ICjwRIPdSgLnH48ORPiXhjl+Ezb0MnhfdhoYrJqJ+dIX3R5c9/l/if7pOKEAPeT4KA4sdREr5AuOKxcK8ROjFA0tVbHGr6XYt7OWmhfXYntCq52Aqmk4qD/DfwyfWTUu0dpT8tiZkYYo7LWpM6TYCN3BvCPIBYvSDL1PWxPEZkoOlMPF/4L7bg3XZF+qUzAle5agNi951Zvk+jZ+BFx0KC790LuViQcZl97lJEmcBV5rGwuHDzWAh8pUTX9YT+w31MI8NhozzURIg==
         * */
        try {
            context->process(buffer);
        }catch (std::invalid_argument& e){
            cerr<<e.what()<<endl;
            context->process(buffer);
        }


        //http://en.cppreference.com/w/cpp/error/exception_ptr
        /*
        try {
            unique_ptr<string> decodedStr = Crypto::decryptRequest(&buffer[0]);
            cout<<*decodedStr <<endl;
        }catch(std::bad_exception& e){
            cout<<e.what()<<endl;
        }catch(std::invalid_argument& e){
            cout<<e.what()<<endl;
        }

*/
        if (bytesReceived ==0) {
            //exit = true;
            this->socket().close();
            std::cout << "No data" << endl;
        }

        //int val=this->socket().sendBytes(reinterpret_cast<void*> (buf), BUF_SIZE-1);
        //if (val<0)
    }
    
}

int ServerConnection::writeToSocket(const std::string &message) {
    return this->socket().sendBytes(message.c_str(),message.size());
}
