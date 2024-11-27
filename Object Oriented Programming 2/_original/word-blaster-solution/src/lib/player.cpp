#include "player.h"

namespace WordBlasterTheGame {

  Player::Player(std::string nickname) { 
    this->nickname = nickname;
  }

  std::string Player::get_nickname(void) { 
    return nickname;
  }

};