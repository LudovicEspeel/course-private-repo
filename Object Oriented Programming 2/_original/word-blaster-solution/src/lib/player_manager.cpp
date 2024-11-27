#include "player_manager.h"

namespace WordBlasterTheGame {

  Player * PlayerManager::get_player_by_nickname(std::string nickname) {
    for (auto && player : players) {
      if (player->get_nickname() == nickname) {
        return player;
      }
    }

    return add_player(nickname);
  }

  Player * PlayerManager::add_player(std::string nickname) {
    Player * player = new Player(nickname);
    players.push_back(player);
    return player;
  }

  PlayerManager::~PlayerManager(void) {
    for (unsigned int i = 0; i < players.size(); i++) {
      delete players[i];
      players[i] = nullptr;
    }
    players.clear();
  }

};