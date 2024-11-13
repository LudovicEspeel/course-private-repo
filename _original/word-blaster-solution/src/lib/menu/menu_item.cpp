#include "menu_item.h"

namespace WordBlasterTheGame {

  MenuItem::MenuItem(std::string label, Screen nextScreen) {
    this->label = label;
    this->nextScreen = nextScreen;
  }

  std::string MenuItem::get_label(void) {
    return label;
  }

  Screen MenuItem::get_next_screen(void) {
    return nextScreen;
  }

};