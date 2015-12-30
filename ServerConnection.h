/* 
 * File:   TCPconnection.h
 * Author: user
 *
 * Created on December 9, 2015, 12:31 PM
 */

#ifndef TCPCONNECTION_H
#define	TCPCONNECTION_H
#include "Poco/Net/TCPServerConnection.h"
#include <Poco/Net/StreamSocket.h>
#include <memory>
#include "Poco/StringTokenizer.h"

//#include "User.h"
class User;
using Poco::StringTokenizer;
using Poco::Net::TCPServerConnection;
using Poco::Net::StreamSocket;

class ServerConnection : public TCPServerConnection {
public:
    /** called by TCPserver
     *ServerConnection(const ServerConnection& orig);
     */
    ServerConnection(const StreamSocket& client);
    
    /** TCPServer will invoke distructor when connection ended.
     * Therefore do not delete the object by yourself
     */
            
    ~ServerConnection();
    
    
    void run();
    /**
     * 
     * @param idle_time_from_last_packet 
     *       :The time (in seconds) the connection needs to remain 
             idle before TCP starts sending keepalive probes (TCP_KEEPIDLE socket option)
     * @param ack_packets
     *  :The maximum number of keepalive probes TCP should 
             send before dropping the connection. (TCP_KEEPCNT socket option)
     * @param ack_interval
     * :The time (in seconds) between individual keepalive probes.
            (TCP_KEEPINTVL socket option)
     * 
     */
    void setConnectionCheckParams(int idle_time_from_last_packet, int ack_packets, int ack_interval);
   
    void setContext (std::shared_ptr<User> context);
    


private:
    std::shared_ptr<User> context;

};

#endif	/* TCPCONNECTION_H */

