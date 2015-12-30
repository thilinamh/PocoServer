cmake_minimum_required(VERSION 3.3)
project(PocoServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Utils.cpp Utils.h
        ServerConnection.cpp ServerConnection.h
        TCPClientConnectionFactory.cpp TCPClientConnectionFactory.h
        UserStructure/User.cpp UserStructure/User.hxx
        UserStructure/User-odb.cxx UserStructure/User-odb.hxx
        ClientRequest.cpp ClientRequest.h
        Requests/RequestInterface.h Requests/Behaviours/RegistrationBehavior.cpp
        Requests/Behaviours/RegistrationBehavior.h Requests/CommunityRequest.cpp
        Requests/CommunityRequest.h Requests/EnterpriseRequest.cpp
        Requests/EnterpriseRequest.h Requests/RequestState/State.h
        Requests/RequestState/RegistrationState.cpp Requests/RequestState/RegistrationState.h
        Requests/RequestState/VerificationState.cpp Requests/RequestState/VerificationState.h
        Requests/RequestState/InitalState.cpp Requests/RequestState/InitalState.h
        Requests/Behaviours/RequestBehaviour.cpp Requests/Behaviours/RequestBehaviour.h Requests/Behaviours/RequestBehaviour.cpp Requests/Behaviours/RequestBehaviour.h Requests/Behaviours/RegistrationBehaviourEnterprise.cpp Requests/Behaviours/RegistrationBehaviourEnterprise.h Requests/Behaviours/RegistrationBehaviourCommunity.cpp Requests/Behaviours/RegistrationBehaviourCommunity.h UserStructure/EnterpriseUser.cpp UserStructure/EnterpriseUser.h UserStructure/CommunityUser.cpp UserStructure/CommunityUser.h Requests/Behaviours/ConferenceBehaviourEnterprise.cpp Requests/Behaviours/ConferenceBehaviourEnterprise.h Requests/Behaviours/VerificationBehaviourCommunity.cpp Requests/Behaviours/VerificationBehaviourCommunity.h)
add_executable(PocoServer ${SOURCE_FILES})

#INCLUDE_DIRECTORIES(/usr/local/include/odb)
#LINK_DIRECTORIES(/usr/local/lib)
#TARGET_LINK_LIBRARIES(TestPoco PocoFoundation PocoNet)

#set(POCO_ROOT "/usr/local/include/")
#set(Poco_INCLUDE_DIR "/usr/local/include/Poco")
#set(Poco_LIBRARY_DIR "/usr/local/lib")


#include_directories(${POCO_ROOT})
#include_directories(${Poco_INCLUDE_DIRS})
#link_directories(${Poco_LIBRARY_DIRS})
find_library(POCO_FOUNDATION PocoFoundation)
find_library(CRYPTO crypto)
find_library(SSL ssl)
find_library(ODB_Mysql odb-mysql)
find_library(ODB odb)

#${CRYPTO} ${SSL}
target_link_libraries(PocoServer ${POCO_FOUNDATION}  PocoNet ${CRYPTO} ${SSL} ${ODB} ${ODB_Mysql} )