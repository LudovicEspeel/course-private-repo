#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

namespace Bios {

  class Terminal {

    public:
      /**
       * @brief Clear the terminal screen.
       */
      static void clear(void);

      /**
       * @brief Flush the internal std out buffer.
       */
      static void flush(void);

    public:
      /**
       * @brief Hide the cursor from the terminal
       */
      static void hide_cursor(void);

      /**
       * @brief Show the cursor again
       */
      static void show_cursor(void);

      /**
       * @brief Move the cursor to the XY position in the terminal.
       * (0, 0) is top left
       * 
       * @param x the x coordinate to move the cursor too
       * @param y the y coordinate to move the cursor too
       */
      static void move_cursor(unsigned int x, unsigned int y);

    public:
      /**
       * @brief Set the foreground text color in the terminal.
       * 
       * @param color Named color from the colors map (ex. red, green, ...)
       * @param bright Indicate if the color should be the bright variant
       */
      static void foreground_color(std::string color, bool bright=false);

      /**
       * @brief Reset the foreground text color back to its default.
       * 
       */
      static void reset_foreground_color(void);

      /**
       * @brief Set the background color in the terminal.
       * 
       * @param color Named color from the colors map (ex. red, green, ...)
       * @param bright Indicate if the color should be the bright variant
       */
      static void background_color(std::string color, bool bright=false);

      /**
       * @brief Reset the background color back to its default.
       * 
       */
      static void reset_background_color(void);

    public:
      const static std::map<std::string,std::string> colors;

    public:
      enum class Key {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ENTER,
        ESC,
        SPACE,
        CTRL_C,
        UNKNOWN,
        NONE,
      };

#ifdef __linux__

      public:
        // A mapping of the Keys to their actual key codes
        const static std::map<Key, std::vector<int>> key_map;

      /**
       * @brief Check if a key has been pressed on the keyboard.
       * 
       * @returns Key enum value or Key::NONE if none has been pressed
       * 
       */
      static Key get_key_press(void);

#endif

  };

};