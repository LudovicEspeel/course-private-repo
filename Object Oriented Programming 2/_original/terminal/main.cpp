#include <iostream>
#include <chrono>
#include <thread>
#include "terminal.h"

using namespace std;
using namespace Bios;

int main() {

  Terminal::clear();
  Terminal::hide_cursor();
  Terminal::background_color("white");
  Terminal::foreground_color("blue", true);

  for (int i = 0; i < 10; i++) {

    Terminal::move_cursor(5, 5);
    printf("}");
    Terminal::flush();
    std::this_thread::sleep_for(500ms);

    Terminal::move_cursor(5, 5);
    printf(">");
    Terminal::flush();
    std::this_thread::sleep_for(500ms);

  }

  Terminal::show_cursor();
  Terminal::reset_background_color();
  Terminal::reset_foreground_color();
  Terminal::clear();

  cout << "Let's wait for some keypresses. Hit CTRL-C to stop." << endl;

  while (true) {
    Terminal::Key key = Terminal::get_key_press();
    if (key != Terminal::Key::NONE) {
      Terminal::clear();
      switch (key) {
        case Terminal::Key::LEFT: cout << "You pressed LEFT" << endl; break;
        case Terminal::Key::RIGHT: cout << "You pressed RIGHT" << endl; break;
        case Terminal::Key::UP: cout << "You pressed UP" << endl; break;
        case Terminal::Key::DOWN: cout << "You pressed DOWN" << endl; break;
        case Terminal::Key::ENTER: cout << "You pressed ENTER" << endl; break;
        case Terminal::Key::SPACE: cout << "You pressed SPACE" << endl; break;
        case Terminal::Key::ESC: cout << "You pressed ESC" << endl; break;
      }
    }

    if (key == Terminal::Key::CTRL_C) exit(0);
  }

  return 0;
}