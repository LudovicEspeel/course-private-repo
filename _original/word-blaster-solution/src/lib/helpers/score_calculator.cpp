#include "score_calculator.h"

#include <cmath>

namespace WordBlasterTheGame {

  unsigned int ScoreCalculator::determine_score(std::string word,
      Difficulty::Level difficulty, unsigned int milliseconds) {

    return ceil(1000 * word.length() * (((int)difficulty+1)*42) / milliseconds);
  }

};