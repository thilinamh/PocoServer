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


using Poco::Net::TCPServer;
using Poco::Net::TCPServerConnectionFactory;
//using Poco::Net::TCPServerConnectionFactoryImpl<Client_Connection>;
using namespace std;

int main(int argc, char** argv)
{
    using namespace std;
    using namespace odb::core;
    try {
        unique_ptr<odb::database> db(new odb::mysql::database(
                "testuser",// database login name
                "password", // database password
                "testdb" // database name
        ));

        // The following alternative version only creates the schema if it
        // hasn't already been created. To detect the existence of the schema
        // this version tries to query the database for a person object. If
        // the corresponding table does not exist, then an exceptions will be
        // thrown in which case we proceed to creating the schema.

        {
          transaction t (db->begin ());

          try
          {
            db->query<User> (false);
              cout<<"trying user"<<endl;
              //schema_catalog::drop_schema (*db);
          }
          catch (const odb::exception& e)
          {
              cout<<"exception caugth"<<endl;
            schema_catalog::create_schema (*db);
          }

          t.commit ();
        }

        }catch(odb::mysql::database_exception& e){
            cerr<<e.what()<<endl;

            throw e;
        }

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