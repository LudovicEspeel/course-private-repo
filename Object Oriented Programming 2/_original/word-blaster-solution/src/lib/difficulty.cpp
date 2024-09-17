#include "difficulty.h"

namespace WordBlasterTheGame {

  Difficulty::Level Difficulty::from_string(std::string difficulty) {
    if (difficulty == "Easy") return Level::EASY;
    else if (difficulty == "Hard") return Level::HARD;
    else return Level::NORMAL;
  }

  std::vector<std::string> Difficulty::get_all(void) {
    std::vector<std::string> difficulties;
    difficulties.push_back("Easy");
    difficulties.push_back("Normal");
    difficulties.push_back("Hard");
    return difficulties;
  }

};
