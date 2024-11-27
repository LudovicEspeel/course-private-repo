#include "word_blaster.h"
#include "user_io.h"

namespace WordBlasterTheGame {

  void WordBlaster::start(void) {
    UserIO::show_welcome_screen();
    currentPlayer = playerManager.get_player_by_nickname(UserIO::request_nickname());
    game = new Game(currentPlayer, &playerManager);
    show_main_menu();
  }

  void WordBlaster::show_main_menu(void) {
    Menu mainMenu = build_main_menu();
    Screen next;
    do {
      next = UserIO::request_menu_selection(&mainMenu).get_next_screen();

      switch (next) {
        case Screen::DIFFICULTY:
          game->change_difficulty(request_difficulty());
          break;

        case Screen::PLAY:
          game->play();
          break;

        case Screen::SCOREBOARD:
          UserIO::show_scoreboard(game->get_scoreboard());
          break;

        default: break;
      }
    } while (next != Screen::EXIT);
  }

  Difficulty::Level WordBlaster::request_difficulty(void) {
    Menu difficultyMenu = build_difficulty_options();
    UserIO::request_menu_selection(&difficultyMenu);
    return Difficulty::from_string(difficultyMenu.get_selected_item().get_label());
  }

  WordBlaster::~WordBlaster(void) {
    delete game;
  }

  Menu WordBlaster::build_main_menu(void) {
    Menu mainMenu("Main Menu");
    mainMenu.add("Play New Game", Screen::PLAY);
    mainMenu.add("Change Difficulty", Screen::DIFFICULTY);
    mainMenu.add("Show Scoreboard", Screen::SCOREBOARD);
    mainMenu.add("Exit", Screen::EXIT);
    return mainMenu;
  }

  Menu WordBlaster::build_difficulty_options(void) {
    Menu difficultyMenu("Difficulty Setting");
    for (auto && difficulty : Difficulty::get_all()) {
      difficultyMenu.add(difficulty, Screen::MAIN_MENU);
    }
    return difficultyMenu;
  }

};