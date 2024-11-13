#include "score_comparator.h"

namespace WordBlasterTheGame {

  bool ScoreComparator::operator() (Score left, Score right) {
    return left.total_score() < right.total_score();
  }

};