// Source on ANSI Codes: https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html

#include "terminal.h"

#ifdef __linux__
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#endif

namespace Bios {

  namespace ConsoleIO {

#ifdef __linux__

    bool isConfigured = false;   // Set true when original terminal is set
    struct termios orig_termios;
    struct termios new_termios;

    // Source: https://stackoverflow.com/questions/448944/c-non-blocking-keyboard-input
    // Also see: https://man7.org/linux/man-pages/man3/termios.3.html

    void reset_terminal_mode() {
      tcsetattr(0, TCSANOW, &orig_termios);
    }

    void set_conio_terminal_mode() {
      if (!isConfigured) {
        /* take two copies - one for now, one for later */
        tcgetattr(0, &orig_termios);
        memcpy(&new_termios, &orig_termios, sizeof(new_termios));

        /* register cleanup handler */ 
        atexit(reset_terminal_mode);

        /* set the new terminal mode */
        // orig_termios.c_lflag &= ~ECHO;    // HACK FOR ECHO !
        // new_termios.c_lflag &= ~ICANON;
        // new_termios.c_lflag &= ~ECHO;    /* turn off ECHO */
        cfmakeraw(&new_termios);    // Act as old Version 7 terminal driver (no echo, char per char)

        isConfigured = true;
      }

      tcsetattr(0, TCSANOW, &new_termios);    // TCSANOW — Make the change immediately.
    }

    bool kbhit() {
      struct timeval tv = { 0L, 0L };
      fd_set fds;
      FD_ZERO(&fds);
      FD_SET(0, &fds);
      return select(1, &fds, NULL, NULL, &tv);
    }

    int getch() {
      int r;
      unsigned char c;
      if ((r = read(0, &c, sizeof(c))) < 0) return r;
      else return c;
    }

#endif

  };

  void Terminal::clear(void) {
    system("clear");
  }

  void Terminal::flush(void) {
    fflush(stdout);
  }

  void Terminal::hide_cursor(void) {
    printf("\33[?25l");
  }

  void Terminal::show_cursor(void) {
    printf("\e[?25h");
  }

  void Terminal::move_cursor(unsigned int x, unsigned int y) {
    printf("%c[%d;%df", 0x1B, y, x);
  }

  void Terminal::foreground_color(std::string color, bool bright) {
    std::string colorCode = Terminal::colors.at(color);
    printf("%s%s", colorCode.substr(0, colorCode.length()-1).c_str(), (bright ? ";1m" : "m"));
    flush();
  }

  void Terminal::reset_foreground_color(void) {
    printf("\u001b[0m");
    flush();
  }

  void Terminal::background_color(std::string color, bool bright) {
    std::string colorCode = Terminal::colors.at(color);
    colorCode.replace(colorCode.find('3'), 1, "4");   // Replace 3 by 4 in colorCode for background
    printf("%s%s", colorCode.substr(0, colorCode.length()-1).c_str(), (bright ? ";1m" : "m"));
    flush();
  }

  void Terminal::reset_background_color(void) {
    printf("\u001b[0m");
    flush();
  }

  const std::map<std::string,std::string> Terminal::colors = {
    { "black", "\u001b[30m" },
    { "red", "\u001b[31m" },
    { "green", "\u001b[32m" },
    { "yellow", "\u001b[33m" },
    { "blue", "\u001b[34m" },
    { "magenta", "\u001b[35m" },
    { "cyan", "\u001b[36m" },
    { "white", "\u001b[37m" },
  };

#ifdef __linux__

  const std::map<Terminal::Key, std::vector<int>> Terminal::key_map = {
    { Terminal::Key::UP,      { 27, 91, 65 } },
    { Terminal::Key::DOWN,    { 27, 91, 66 } },
    { Terminal::Key::LEFT,    { 27, 91, 68 } },
    { Terminal::Key::RIGHT,   { 27, 91, 67 } },
    { Terminal::Key::ENTER,   { 13 } },
    { Terminal::Key::ESC,     { 27 } },
    { Terminal::Key::SPACE,   { 32 } },
    { Terminal::Key::CTRL_C,  { 3 } },
  };

  Terminal::Key Terminal::get_key_press(void) {
    ConsoleIO::set_conio_terminal_mode();

    Key outputKey = Key::NONE;

    std::vector<int> keys;
    while (ConsoleIO::kbhit()) {
      keys.push_back(ConsoleIO::getch());
    }

    // Use for debugging and new key code addition
    // if (keys.size() > 0) {
    //   std::cout << "Got " << keys.size() << " keycodes: ";
    //   for(auto && key : keys) {
    //     std::cout << key << " ";
    //   }
    //   std::cout << std::endl;
    // }

    if (keys.size() > 0) {
      for (auto && it : key_map) {
        if (keys == it.second) {
          return it.first;
        }
      }
      return Key::UNKNOWN;
    }
    return Key::NONE;

    ConsoleIO::reset_terminal_mode();
    return outputKey;
  }

#endif

};
