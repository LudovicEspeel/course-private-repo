#pragma once

#include <string>
#include "screen.h"

namespace WordBlasterTheGame {

  class MenuItem {

    public:
      /**
       * Constructor of MenuItem.
       * 
       * @param label: the label that should be
       * displayed for the menu item
       * @param nextScreen: the screen to which the
       * user is navigated when this item is selected.
       */
      MenuItem(std::string label, Screen nextScreen);

      /**
       * Get the label for the menu item.
       * 
       * @return an std::string containing the label
       * of the menu item
       */
      std::string get_label(void);

      /**
       * Get the next screen for the menu item.
       * 
       * @return the next screen to which needs
       * to be navigated.
       */
      Screen get_next_screen(void);

    private:
      std::string label = "";
      Screen nextScreen = Screen::NOT_SET;
  };

};