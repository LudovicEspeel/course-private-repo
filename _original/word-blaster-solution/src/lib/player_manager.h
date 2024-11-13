#pragma once

#include <vector>
#include <string>
#include "player.h"

namespace WordBlasterTheGame {

  /**
   * Track players in the game. For example
   * for the scoreboard.
   */
  class PlayerManager {

    public:
      /**
       * Get a player from the list by
       * his/her nickname. If the player
       * does not exist yet, a new player
       * is returned.
       * 
       * @param nickname: the nickname of the player
       * 
       * @returns a pointer to an existing or new player object
       */
      Player * get_player_by_nickname(std::string nickname);

    public:
      /**
       * Destructor of PlayerManager. Deletes
       * all dynamically allocated players.
       */
      ~PlayerManager(void);

    private:
      /**
       * Create a new player with the given nickname.
       * 
       * @param nickname: the nickname of the player
       * 
       * @returns a pointer to a new player object
       */
      Player * add_player(std::string nickname);

    private:
      std::vector<Player*> players;

  };

};