#include "score.h"

namespace WordBlasterTheGame {

  Score::Score(Player * player)
    : Score(player, 0) {
      // Call other constructor
  }

  Score::Score(Player * player, unsigned int score) {
    this->player = player;
    this->score = score;
  }

  void Score::add_to_score(unsigned int delta) {
    score += delta;
  }

  unsigned int Score::total_score(void) {
    return score;
  }

  Player * Score::get_player(void) {
    return player;
  }

};