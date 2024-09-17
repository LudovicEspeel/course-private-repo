#include "menu.h"

namespace WordBlasterTheGame {

  Menu::Menu(std::string title) {
    this->title = title;
  }

  void Menu::add(std::string item, Screen nextScreen) {
    items.push_back({item, nextScreen});
    currentlySelected = 0;
  }

  std::vector<std::string> Menu::get_labels(void) {
    std::vector<std::string> labels;
    for (auto && item : items) {
      labels.push_back(item.get_label());
    }
    return labels;
  }

  void Menu::select_next(void) {
    currentlySelected = ((currentlySelected+1) % items.size());
  }

  void Menu::select_previous(void) {
    currentlySelected--;
    if (currentlySelected < 0) {
      currentlySelected = items.size() - 1;
    }
  }

  MenuItem Menu::get_selected_item(void) {
    if (currentlySelected < 0) return {"", Screen::NOT_SET};

    return items[currentlySelected];
  }

  std::string Menu::get_title(void) {
    return title;
  }

};