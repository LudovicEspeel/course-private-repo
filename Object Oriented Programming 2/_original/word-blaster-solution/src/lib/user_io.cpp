#include "user_io.h"

#include <iostream>
#include "helpers/terminal.h"
#include "helpers/string_helper.h"

using namespace std;

namespace WordBlasterTheGame {

// How most screens should look:
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~     Word Blaster - Next Gen Typing Motivator     ~     game_title
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~                                                  ~
// ~ Use the arrow keys to navigate through the menu  ~     instructions
// ~           and ENTER to select an item.           ~
// ~                                                  ~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~                    Main Menu                     ~     screen name
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~                                                  ~
// ~    ==> 1. Play New Game                          ~     content
// ~        2. Change Difficulty                      ~
// ~        3. Show Scoreboard                        ~
// ~        4. Exit                                   ~
// ~                                                  ~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  void UserIO::show_welcome_screen(void) {
    show_game_title();

    show_instructions("PRESS ENTER TO CONTINUE");

    std::vector<std::string> content;
    content.push_back("Please be carefull. This is a very addictive game and may lead to many wasted hours!");
    content.push_back("");
    content.push_back("The original developer has long wasted away typing himself to death.");
    content.push_back("");
    content.push_back("You are warned ...");
    show_content(content);

    press_enter_to_continue();
  }

  std::string UserIO::request_nickname(void) {
    std::string nickname = "";
    do {
      show_game_title();
      show_instructions("Please enter the nickname with which you would like to play.");

      cout << endl << "Nickname: ";
      nickname = request_string_input();
    } while(nickname == "");

    return nickname;
  }

  MenuItem UserIO::request_menu_selection(Menu * menu) {
    Terminal::Key key;
    do {
      show_game_title();
      show_instructions("Use the arrow keys to navigate through the menu and ENTER to select an item.");
      show_screen_name(menu->get_title());
      show_menu(menu);
      key = Terminal::pressed_key();
      if (key == Terminal::Key::DOWN) {
        menu->select_next();
      } else if (key == Terminal::UP) {
        menu->select_previous();
      }
    } while (key != Terminal::Key::ENTER);

    return menu->get_selected_item();
  }

  void UserIO::show_game_instructions(void) {
    show_game_title();
    show_instructions("PRESS ENTER TO START");
    show_screen_name("Instructions");

    std::vector<std::string> content;
    content.push_back("Type the word correctly as fast possible and confirm using ENTER to score points.");
    content.push_back("");
    content.push_back("Hit ENTER without typing anything to pass the current word.");
    show_content(content);

    press_enter_to_continue();
  }

  std::string UserIO::request_user_attempt_at_word(unsigned int number, std::string word) {
    show_game_title();
    show_instructions("Type the word as fast as possible and hit ENTER.");
    show_screen_name("Playing ...");

    show_empty_boxed_lines(1);
    show_boxed_text("  Word #" + std::to_string(number+1) + ": ", false);
    show_boxed_text(word);
    show_empty_boxed_lines(1);
    show_full_box_line();

    cout << std::endl << "YOU > ";
    return request_string_input();;
  }

  void UserIO::show_final_score(Score score) {
    show_game_title();
    show_instructions("PRESS ENTER TO START");
    show_screen_name("Final score");

    std::vector<std::string> content;
    content.push_back("Your final score is ...");
    content.push_back("");
    content.push_back(std::to_string(score.total_score()));
    show_content(content);

    press_enter_to_continue();
  }

  void UserIO::show_scoreboard(Scoreboard * board) {
    show_game_title();

    show_instructions("PRESS ENTER TO CONTINUE");

    std::vector<std::string> content;
    for (auto && score : board->get_scores()) {
      content.push_back(score.get_player()->get_nickname()
        + " - " + std::to_string(score.total_score()));
    }
    show_content(content);

    press_enter_to_continue();
  }

  void UserIO::show_game_title(void) {
    Terminal::clear();
    show_full_box_line();
    show_boxed_text("Word Blaster - Next Gen Typing Motivator");
    show_full_box_line();
  }

  void UserIO::show_instructions(std::string instructions) {
    show_empty_boxed_lines();
    show_boxed_text(instructions);
    show_empty_boxed_lines();
    show_full_box_line();
  }

  void UserIO::show_screen_name(std::string name) {
    show_boxed_text(name);
    show_full_box_line();
  }

  void UserIO::show_content(std::vector<std::string> lines, bool centered) {
    show_empty_boxed_lines();
    for (auto && line : lines) {
      show_boxed_text(line, centered);
    }
    show_empty_boxed_lines();
    show_full_box_line();
  }

  void UserIO::show_menu(Menu * menu, bool numbered) {
    std::vector<std::string> content = menu->get_labels();

    for (unsigned int i = 0; i < content.size(); i++) {
      std::string prefix = "";
      if (menu->get_selected_item().get_label() == content[i]) {
        prefix = "   ==> ";
      } else {
        prefix = "       ";
      }

      if (numbered) {
        prefix = prefix + std::to_string(i+1) + ". ";
      }
      content[i] = prefix + content[i];
    }
    show_content(content, false);
  }

  void UserIO::press_enter_to_continue(void) {
    request_string_input();
  }

  std::string UserIO::request_string_input(void) {
    std::string input;
    getline(cin, input);
    return input;
  }

  void UserIO::show_boxed_text(std::string text, bool center) {
    std::vector<std::string> lines = StringHelper::wrap_text(text, WIDTH-4);
    for (auto && line : lines) {
      if (center) {
        cout << "~ " << StringHelper::center_text(line, WIDTH-4) << " ~" << endl;
      } else {
        cout << "~ " << StringHelper::pad_text(line, WIDTH-4) << " ~" << endl;
      }
    }
  }

  void UserIO::show_empty_boxed_lines(unsigned int count) {
    for (unsigned int i = 0; i < count; i++) {
      cout << "~" << StringHelper::generate_single_character_string(' ', WIDTH-2) << "~" << endl;
    }
  }

  void UserIO::show_full_box_line(void) {
    cout << StringHelper::generate_single_character_string('~', WIDTH) << endl;
  }

};