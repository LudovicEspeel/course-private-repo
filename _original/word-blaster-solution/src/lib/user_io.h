#pragma once

#include <string>
#include "score.h"
#include "scoreboard.h"
#include "menu/menu.h"
#include "difficulty.h"

namespace WordBlasterTheGame {

  /**
   * Process all User IO to the terminal.
   */
  class UserIO {

    public:
      /**
       * Output the welcome screen
       */
      static void show_welcome_screen(void);

      /**
       * Request a nickname from the user
       *
       * @returns the nickname of the user as a string
       */
      static std::string request_nickname(void);

      /**
       * Show the menu to the user and request
       * the user to select an item from the menu.
       * 
       * @param menu: the menu to display to the user
       * 
       * @returns the selected MenuItem from the menu
       */
      static MenuItem request_menu_selection(Menu * menu);

      /**
       * Show the instructions screen that explains how
       * to play the game.
       */
      static void show_game_instructions(void);

      /**
       * Output the next word for the user to type
       * and let the user input an attempt to copy
       * the word.
       *
       * @param number: the index number of the word
       * @param word: word for the user to type
       */
      static std::string request_user_attempt_at_word(unsigned int number, std::string word);

      /**
       * Output the final score of the user.
       *
       * @param score: the final score to be shown
       */
      static void show_final_score(Score score);

      /**
       * Output scoreboard screen with all the
       * player scores.
       *
       * @param board: pointer to Scoreboard object
       * that contains the player scores.
       */
      static void show_scoreboard(Scoreboard * board);

    private:
      /**
       * Show the game title region for a screen which
       * contains the title of the game.
       */
      static void show_game_title(void);

      /**
       * Show the instructions region for a screen.
       * 
       * @param instructions: the instructions for the current
       * screen
       */
      static void show_instructions(std::string instructions);

      /**
       * Show the name of the current screen.
       * 
       * @param name: the name / title of the current screen
       */
      static void show_screen_name(std::string name);

      /**
       * Display boxed content. All text is automatically boxed
       * and wrapped.
       * 
       * @param lines: the lines of content to show as an std::vector
       * std::string objects
       * @param centered: set to true to center each line
       */
      static void show_content(std::vector<std::string> lines, bool centered=true);

      /**
       * Request the user to press the ENTER key before
       * continuing to the next screen.
       */
      static void press_enter_to_continue(void);

      /**
       * Read a string from the terminal.
       */
      static std::string request_string_input(void);

      /**
       * Output a menu to the terminal with the given title.
       * 
       * @param menu: the menu that needs to be shown in
       * the terminal
       * @param numbered: indicate if each label should be prefixed
       * with a number from 1 to the size of the vector
       */
      static void show_menu(Menu * menu, bool numbered=true);

      /**
       * Show an empty lines boxed in the border.
       * 
       * @param count: number of lines to show
       */
      static void show_empty_boxed_lines(unsigned int count=1);

      /**
       * Show text boxed in the border. The text is automatically
       * wrapped when needed.
       * 
       * @param text: the text to display
       * @param center: setting this to true centers the text within
       * the border
       */
      static void show_boxed_text(std::string text, bool center=true);

      /**
       * Show full box line consisting of border characters filling
       * the the while line.
       * 
       */
      static void show_full_box_line(void);

    private:
      static const unsigned int WIDTH = 52;

  };

};