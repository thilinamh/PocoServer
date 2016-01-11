//
// Created by user on 12/21/15.
//

#include "CommunityUser.h"
#include "../Requests/Behaviours/Community/BehaviourContainerCOMM.h"

CommunityUser::CommunityUser(const StreamSocket &socket): User(socket, new BehaviourContainerCOMM()) {
cout<<"CommiunityUser Created"<<endl;
}

void CommunityUser::bindWithServer() {
  // Before calling shared_from_this(),
  // there should be at least one std::shared_ptr p that owns *this
  tcpConnection->setContext(shared_from_this());
}

BehaviourContainer &CommunityUser::getBehaviours() {

    return *(User::_behaviours);

}
