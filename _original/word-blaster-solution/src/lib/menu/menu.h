#pragma once

#include <vector>
#include <string>
#include "menu_item.h"

namespace WordBlasterTheGame {

  class Menu {

    public:
      /**
       * Constructor for Menu.
       * 
       * @param title: the title for the menu that describes
       * the items that are contained in the menu.
       */
      Menu(std::string title);

    public:
      /**
       * Add an item to the menu
       * 
       * @param item: the label for the item to
       * be shown to the user.
       * @param nextScreen: the next screen that
       * should be shown after the user has made
       * his/her choice
       */
      void add(std::string item, Screen nextScreen);

      /**
       * Get an std::vector containing all the labels
       * as std::string's for the menu.
       * 
       * @return an std::vector<std::string> that contains
       * the labels for the menu items
       */
      std::vector<std::string> get_labels(void);

    public:
      /**
       * Select the next item in the menu list. If the
       * currently selected item was the last
       * in the list, the selector will jump to the top
       * of the menu.
       */
      void select_next(void);

      /**
       * Select the previous item in the menu list. If the
       * currently selected item was the first
       * in the list, the selector will jump to the bottom
       * of the menu.
       */
      void select_previous(void);

      /**
       * Get the item that is currently selected.
       * 
       * @returns the currently selected item
       */
      MenuItem get_selected_item(void);

      /**
       * Get the title for the menu.
       * 
       * @returns the title of the menu as an
       * std::string
       */
      std::string get_title(void);

    private:
      std::vector<MenuItem> items;
      int currentlySelected = -1;
      std::string title = "";
  };

};