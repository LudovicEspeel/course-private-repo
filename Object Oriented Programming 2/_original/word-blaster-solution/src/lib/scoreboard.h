#pragma once

#include <vector>
#include "score.h"
#include "player_manager.h"

namespace WordBlasterTheGame {

  /**
   * Track the top scores of players.
   * Allows loading and saving scores.
   */
  class Scoreboard {

    public:
      /**
       * Create a Scoreboard for the Game
       *
       * @param playerManager: a pointer to the
       * player manager object.
       */
      Scoreboard(PlayerManager * playerManager);

    public:
      /**
       * Add a score to the
       * scoreboard to be tracked.
       * 
       * @param score: score to be added to the board
       */
      void add(Score score);

      /**
       * Save the scores to a file.
       * 
       * @param filename: path to the file where the
       * scores need to be saved.
       */
      void save(std::string filename);

      /**
       * Get the list of scores as an std::vector.
       * 
       * @returns an std::vector of Score objects
       */
      std::vector<Score> get_scores(void);

      /**
       * Load the scores from a file.
       * 
       * @param filename: path to the file where the
       * scores are stored.
       */
      void load(std::string filename);

    private:
      /**
       * Sort the scoreboard scores from high
       * to low.
       */
      void sort(void);

      /**
       * Limit the scores tracked by the scoreboard
       * to the maximum number of entries.
       */
      void limit(void);

    private:
      std::vector<Score> scores;
      PlayerManager * playerManager = nullptr;
      const static unsigned int ENTRY_LIMIT = 10;
  };

};