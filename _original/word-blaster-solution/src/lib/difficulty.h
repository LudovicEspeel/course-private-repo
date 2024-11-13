#pragma once

#include <string>
#include <vector>

namespace WordBlasterTheGame {

  class Difficulty {
    public:
      enum Level {
        EASY,
        NORMAL,
        HARD
      };

    public:
      /**
       * Convert difficulty as a string to an enum
       * of type Level.
       *
       * @param difficulty: the difficulty represented as
       * a string.
       *
       * @returns the difficulty as an enum of type Level.
       */
      static Level from_string(std::string difficulty);

      /**
       * Get a list of possible difficulties as an 
       * std::vector of std::string objects.
       *
       * @return an std::vector<std::string> containing
       * a list of the possible difficulties for the game.
       */
      static std::vector<std::string> get_all(void);
  };

};