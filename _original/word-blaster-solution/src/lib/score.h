#pragma once

#include <string>
#include "player.h"

namespace WordBlasterTheGame {

  /**
   * Track the score of a player.
   */
  class Score {

    public:
      /**
       * Create a new score for the player.
       *
       * @param player: a pointer to the player object
       * to which the score object belongs
       */
      Score(Player * player);

      /**
       * Create a Score object for the player with
       * a predefined score.
       *
       * @param player: a pointer to the player object
       * to which the score object belongs
       * @param score: the score for the player
       */
      Score(Player * player, unsigned int score);

    public:
      /**
       * Add score for a word that was typed correctly.
       *
       * @param delta: amount to add to the score
       */
      void add_to_score(unsigned int delta);
      
    public:
      /**
       * Get the total score.
       *
       * @returns the total score as an unsigned integer
       */
      unsigned int total_score(void);
      
    public:
      /**
       * Get the player to which this score belongs.
       *
       * @returns a pointer to the player of the score
       */
      Player * get_player(void);

    private:
      unsigned int score = 0;
      Player * player = nullptr;
  };

};