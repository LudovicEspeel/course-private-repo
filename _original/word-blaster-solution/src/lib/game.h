#pragma once

#include "word_list.h"
#include "score.h"
#include "scoreboard.h"
#include "player_manager.h"
#include "difficulty.h"

namespace WordBlasterTheGame {

  /**
   * The Game class contains the basic
   * logic of the WordBlaster game.
   */
  class Game {

    public:
      /**
       * Create a game for the current player.
       *
       * @param player: a pointer to the player for
       * which the game is intended.
       * @param playerManager: a pointer to the
       * player manager object.
       */
      Game(Player * player, PlayerManager * playerManager);

    public:
      /**
       * Play the game. This will requests words to be typed by
       * the user.
       *
       */
      void play(void);

      /**
       * Change the difficulty of the game.
       * 
       * @param difficulty: the difficulty to change to
       */
      void change_difficulty(Difficulty::Level difficulty);

      /**
       * Get the current scoreboard.
       * 
       * @returns pointer to the scoreboard
       * for the current difficulty.
       */
      Scoreboard * get_scoreboard(void);

    private:
      /**
       * Load the word dictionary for the
       * current difficulty.
       */
      void load_dictionary(void);

      /**
       * Load the scores from the correct file
       * into the scoreboard for the
       * current difficulty.
       */
      void load_scoreboard(void);

      /**
       * Save the scores of the scoreboard
       * to the correct file based on the
       * current difficulty.
       */
      void save_scoreboard(void);

    private:
      WordList words;
      Player * player = nullptr;
      Scoreboard scoreboard;
      PlayerManager * playerManager = nullptr;
      unsigned int numberOfWordsToType = 10;

      Difficulty::Level difficulty = Difficulty::Level::NORMAL;

      // Static variables are not kept on an object base
      // but rather stored per class
      const static std::string DICTIONARY_FILES[];
      const static std::string SCOREBOARD_FILES[];
  };

};