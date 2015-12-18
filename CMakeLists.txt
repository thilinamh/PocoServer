cmake_minimum_required(VERSION 3.3)
project(PocoServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Utils.cpp Utils.h
        ServerConnection.cpp ServerConnection.h
        TCPClientConnectionFactory.cpp TCPClientConnectionFactory.h
        UserStructure/User.cpp UserStructure/User.h
        ClientRequest.cpp ClientRequest.h
        Requests/RequestInterface.h Requests/RegistrationBehavior.cpp
        Requests/RegistrationBehavior.h Requests/CommunityRequest.cpp
        Requests/CommunityRequest.h Requests/EnterpriseRequest.cpp
        Requests/EnterpriseRequest.h Requests/RequestState/State.h
        Requests/RequestState/RegistrationState.cpp Requests/RequestState/RegistrationState.h
        Requests/RequestState/VerificationState.cpp Requests/RequestState/VerificationState.h
        Requests/RequestState/InitalState.cpp Requests/RequestState/InitalState.h
        Requests/RequestBehaviour.cpp Requests/RequestBehaviour.h Requests/RequestBehaviour.cpp Requests/RequestBehaviour.h)
add_executable(PocoServer ${SOURCE_FILES})

#INCLUDE_DIRECTORIES(/usr/local/include/)
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

#${CRYPTO} ${SSL}
target_link_libraries(PocoServer ${POCO_FOUNDATION}  PocoNet ${CRYPTO} ${SSL}  )