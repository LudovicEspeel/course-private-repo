#include "scoreboard.h"

#include <iostream>
#include <fstream>
#include <algorithm>    // std::sort
#include "./comparators/score_comparator.h"

namespace WordBlasterTheGame {
  
  Scoreboard::Scoreboard(PlayerManager * playerManager) {
    this->playerManager = playerManager;
  }

  void Scoreboard::add(Score score) {
    scores.push_back(score);
    sort();
    limit();
  }

  void Scoreboard::save(std::string filename) {
    std::ofstream output;
    output.open(filename);    // Default mode is ios::out

    if (!output) {
      std::cerr << "Could not save the scores to the file " << filename << std::endl;
      return;
    }

    // Write the scores to the file
    for (auto && score : scores) {
      output << score.get_player()->get_nickname() << ","
        << score.total_score() << std::endl;
    }

    // Close the file
    output.close();
  }

  std::vector<Score> Scoreboard::get_scores(void) {
    // This will return a copy of the internal std::vector.
    // Not most performant solution but on the other side this way
    // external code cannot change the scores.
    return scores;
  }

  void Scoreboard::load(std::string filename) {
    // Make sure the board is cleared first
    scores.clear();

    // File stream object
    std::ifstream file;
    file.open(filename);

    if (!file) {
      // Let's do nothing here as there are no scores yet.
      // File will be created on save
      return;
    }

    // Read the scores from the file
    do {
      std::string name;
      std::string points;
      
      // The separator can be supplied to getline
      std::getline(file, name, ',');
      std::getline(file, points);

      if (name != "" && points != "") {
        int score = std::stoi(points);
        add(Score(playerManager->get_player_by_nickname(name), score));
      }
    } while (file.good());

    // Close the file
    file.close();
  }

  void Scoreboard::sort(void) {
    ScoreComparator comparator;
    std::sort(scores.begin(), scores.end(), comparator);
    std::reverse(scores.begin(), scores.end());
  }

  void Scoreboard::limit(void) {
    while (scores.size() > ENTRY_LIMIT) {
      scores.pop_back();
    }
  }

};