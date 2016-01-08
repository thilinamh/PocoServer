//
// Created by user on 12/21/15.
//

#include "CommunityUser.h"
#include "../Requests/Behaviours/Community/BehaviourContainerCOMM.h"

CommunityUser::CommunityUser(const StreamSocket &socket):User(socket) {
cout<<"CommiunityUser Created"<<endl;
}

void CommunityUser::bindWithServer() {
  // Before calling shared_from_this(),
  // there should be at least one std::shared_ptr p that owns *this
  tcpConnection->setContext(shared_from_this());
}

BehaviourContainer &CommunityUser::getBehaviours() {
  cout<<"In CommunityUser get behaviour"<<endl;
    if(User::_behaviours.get()==nullptr){
      cout<<"BehaviourContainerCOMM created"<<endl;
      User::_behaviours.reset(new BehaviourContainerCOMM());
    }
    return *(User::_behaviours);

}
