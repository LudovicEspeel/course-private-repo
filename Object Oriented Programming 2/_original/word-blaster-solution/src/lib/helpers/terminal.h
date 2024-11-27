#pragma once

namespace WordBlasterTheGame {

  class Terminal {

    public: enum Key {
      UP,
      DOWN,
      ENTER,
      UNKNOWN
    };

    public:

      /**
       * Wait for the user to press a single key
       * and return the pressed key.
       * 
       * @returns the pressed Key or Key::UNKNOWN
       * if the pressed key is not supported.
       */
      static Key pressed_key(void);

      /**
       * Clear the terminal screen.
       */
      static void clear(void);

      /**
       * Get single character from the terminal.
       * Equivalent to getch() from conio.h
       * 
       * Got this nice  implementation from
       * https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
       *
       * @returns keycode from pressed key.
       */
#ifdef __linux__
      static char getch(void);
#endif

  };

};
