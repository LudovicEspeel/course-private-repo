#include "game.h"

#include "word_loader.h"
#include "user_io.h"
#include "helpers/score_calculator.h"
#include <chrono>   // For timing

namespace WordBlasterTheGame {

  // Alias for long namespace
  using TimePoint = std::chrono::steady_clock::time_point;

  const std::string Game::DICTIONARY_FILES[] = {
    "./dictionaries/easy.txt",
    "./dictionaries/normal.txt",
    "./dictionaries/hard.txt"
  };

  const std::string Game::SCOREBOARD_FILES[] = {
    "./easy_scores.txt",
    "./normal_scores.txt",
    "./hard_scores.txt"
  };

  Game::Game(Player * player, PlayerManager * playerManager)
    : scoreboard(playerManager) {
       // Use constructor initialization list since
       // no default constructor exists for Scoreboard
    this->player = player;
    this->playerManager = playerManager;
    change_difficulty(Difficulty::Level::NORMAL);
  }

  void Game::play(void) {
    UserIO::show_game_instructions();

    Score score(player);   // Create new score object for this play
    for (unsigned int i = 0; i < numberOfWordsToType; i++) {
      // Local variable required because we need the same word
      // at the end to check if it is correct
      std::string wordToType = words.get_random_word();

      TimePoint begin = std::chrono::steady_clock::now();
      std::string userWord = UserIO::request_user_attempt_at_word(i, wordToType);
      TimePoint end = std::chrono::steady_clock::now();

      // Determine difference
      unsigned int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

      // Check correctness and alter score if needed
      if (userWord == wordToType) {
        score.add_to_score(ScoreCalculator::determine_score(
          wordToType, difficulty, milliseconds
        ));
      }
    }

    scoreboard.add(score);
    save_scoreboard();
    UserIO::show_final_score(score);
    UserIO::show_scoreboard(&scoreboard);
  }

  void Game::change_difficulty(Difficulty::Level difficulty) {
    this->difficulty = difficulty;
    load_dictionary();
    load_scoreboard();
  }

  Scoreboard * Game::get_scoreboard(void) {
    return &scoreboard;
  }

  void Game::load_dictionary(void) {
    words.clear();
    WordLoader::load(&words, DICTIONARY_FILES[(int)(difficulty)]);    // Calling static method !!!
  }

  void Game::load_scoreboard(void) {
    scoreboard.load(SCOREBOARD_FILES[(int)(difficulty)]);
  }

  void Game::save_scoreboard(void) {
    scoreboard.save(SCOREBOARD_FILES[(int)(difficulty)]);
  }

};