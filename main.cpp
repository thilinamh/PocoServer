#include "Poco/ThreadPool.h"
#include "Poco/Runnable.h"
#include <Poco/Net/TCPServer.h>
#include <iostream>
#include <memory>
#include "ServerConnection.h"
#include <Poco/Net/TCPServerConnectionFactory.h>
#include "TCPClientConnectionFactory.h"
#include <odb/mysql/database.hxx>
#include <odb/mysql/exceptions.hxx>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>

#include "UserStructure/User.hxx"
#include "UserStructure/User-odb.hxx"
#include "DBconnection.h"

using Poco::Net::TCPServer;
using Poco::Net::TCPServerConnectionFactory;
//using Poco::Net::TCPServerConnectionFactoryImpl<Client_Connection>;
using namespace std;

int main(int argc, char** argv)
{
    DBconnection::getDb();

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