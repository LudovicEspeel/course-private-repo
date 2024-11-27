#pragma once

#include "game.h"
#include "player.h"
#include "player_manager.h"
#include "menu/menu.h"

namespace WordBlasterTheGame {

  /**
   * The WordBlaster class controls the overal
   * application flow. Main menu, track the current game,
   * track the player(s), ...
   */
  class WordBlaster {

    public:
      /**
       * Starts the whole WordBlaster application.
       * 
       * Starts by requesting the player's nickname
       * and then shows the game's main menu.
       */
      void start(void);

    public:
      /**
       * WordBlaster destructor. Destroys the game
       * and player that were created dynamically.
       * 
       * Should not be called directly.
       */
      ~WordBlaster(void);

    private:
      /**
       * Show the main menu of the game and let
       * the player navigate through the different
       * options.
       */
      void show_main_menu(void);

      /**
       * Show the difficulty menu to the user
       * and let him/her decide on the game's
       * difficulty setting.
       * 
       * @returns the choosen difficulty
       */
      Difficulty::Level request_difficulty(void);

      /**
       * Build a Menu object for the Main Menu.
       * 
       * @returns a Menu object containing the
       * items for the Main Menu.
       */
      Menu build_main_menu(void);

      /**
       * Build a Menu object for the Difficulty selection Menu.
       * 
       * @returns a Menu object containing the
       * possible difficulties.
       */
      Menu build_difficulty_options(void);

    private:
      PlayerManager playerManager;
      Player * currentPlayer = nullptr;
      Game * game = nullptr;
  };

};