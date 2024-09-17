#pragma once

#include <string>
#include "../difficulty.h"

namespace WordBlasterTheGame {

  /**
   * Score Calculator can determine
   * the score for different game difficulties.
   */
  class ScoreCalculator {

    public:
    /**
     * Calculate the score for the correctly typed word
     * based on the given parameters.
     * 
     * @param word: The word that the user had to type
     * @param difficulty: the game difficulty
     * @param milliseconds: the time it took for the user to
     * type the correct word
     * 
     * @returns the scoring value that can be added to the 
     * current players score.
     */
    static unsigned int determine_score(std::string word,
      Difficulty::Level difficulty, unsigned int milliseconds);

  };

};