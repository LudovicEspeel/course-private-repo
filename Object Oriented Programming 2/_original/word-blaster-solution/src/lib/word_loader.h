#pragma once

#include <string>
#include "word_list.h"

namespace WordBlasterTheGame {

  /**
   * Load words from a file.
   */
  class WordLoader {

    public:
      /**
       * Load all words from a file (lines) and add them
       * to the WordList.
       *
       * @param words: a pointer to a WordList object where the
       * words will added to
       * @param filename: the path to the file that contains the
       * list of words
       */
      static void load(WordList * words, std::string filename);
        // This method is static making it a "class method". No object of
        // WordLoader is required to call the method. This can only be done
        // for methods that do not require any state to be kept between method
        // calls. static is also only prefixed before the prototype in the header file,
        // not in the implementation file.
        // 
        // Why pointer to WordList?
        // Problem with "WordList words" as argument is 
        // that you get a copy of the object. So another list -
        // adding to this list has no effect on original object

  };

};