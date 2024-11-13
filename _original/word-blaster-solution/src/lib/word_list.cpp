#include "word_list.h"

#include <cstdlib>
#include <ctime>

namespace WordBlasterTheGame {

  WordList::WordList(void) {
    // Random needs to be seeded (using time) in the beginning,
    // so this is done in constructor.
    srand(time(NULL));
  }

  void WordList::add(std::string word) {
    words.push_back(word);
  }

  std::string WordList::get_random_word(void) {
    // If the list has no elements, return an empty string
    if (words.size() == 0) return "";

    return words[rand()%words.size()];
  }

  void WordList::clear(void) {
    words.clear();
  }

};