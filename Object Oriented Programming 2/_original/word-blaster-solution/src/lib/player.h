#pragma once

#include <string>

namespace WordBlasterTheGame {

  /**
   * The Player class represents the players
   * that play this game. Each player can choose
   * his/her nickname.
   */
  class Player {

    public:
      /**
       * Constructor for buildind a Player object. This
       * requires the nickname of the player to be provided.
       *
       * @param nickname: a nickname for the player
       */
      Player(std::string nickname);

    public:
      /**
       * Get the nickname of this player.
       *
       * @returns the nickname of the player
       */
      std::string get_nickname(void);

    private:
      std::string nickname = "";

  };

};