#include "Poco/ThreadPool.h"
#include "Poco/Runnable.h"
#include <Poco/Net/TCPServer.h>
#include <iostream>
#include "ServerConnection.h"
#include <Poco/Net/TCPServerConnectionFactory.h>
#include "TCPClientConnectionFactory.h"
using Poco::Net::TCPServer;
using Poco::Net::TCPServerConnectionFactory;
//using Poco::Net::TCPServerConnectionFactoryImpl<Client_Connection>;
using namespace std;

int main(int argc, char** argv)
{

    //TCPServerConnectionFactory::Ptr Ptr ;

    //Ptr= Poco::SharedPtr<TCPServerConnectionFactory> (& obj);
    //TCPServer& r_clientTCP_listner;
    try{
        /*The server takes ownership of the TCPServerConnectionFactory
         and deletes it when it's no longer needed.*/
        TCPServer clientTCP_listner {new ClientConnectionFactory() ,7003};

        clientTCP_listner.start();
        cout<<clientTCP_listner.port()<<endl;
        while(clientTCP_listner.currentConnections()<3);

    }catch(Poco::IOException e){
        cout<<e.displayText()<<endl;
    }




    return 0;
}