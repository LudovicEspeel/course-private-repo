#pragma once

#include <vector>
#include <string>

namespace WordBlasterTheGame {

  /**
   * Track a list of words and allow random selection from the list.
   */
  class WordList {

    public:
      /**
       * Default constructor of a WordList
       */
      WordList(void);

    public:
      /**
       * Add a word to the list
       *
       * @param word: a word (string) to add to the list
       */
      void add(std::string word);

      /**
       * Get a random word from the list
       *
       * @returns a random word from the list or an empty string
       * if the list is empty
       */
      std::string get_random_word(void);

      /**
       * Remove all words from the list
       */
      void clear(void);

    private:
      std::vector<std::string> words;

  };

};