#pragma once

#include "../score.h"

namespace WordBlasterTheGame {

  /**
   * stl comparator for Score objects.
   */
  class ScoreComparator {

    public:
      /**
       * Compare left score to right score and
       * return true if left is smaller than right.
       * 
       * @param left: the first Score object
       * @param right: the second Score object
       * 
       * @returns true if left is smaller than right.
       */
      bool operator() (Score left, Score right);

  };

};