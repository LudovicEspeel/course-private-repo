#include "word_loader.h"
#include <fstream>
#include <iostream>

namespace WordBlasterTheGame {

  void WordLoader::load(WordList * words, std::string filename) {
    // Load from file - see https://oop-cpp.netlify.app/09-file-streams/#reading-from-a-file

    // File stream object
    std::ifstream file;
    file.open(filename);

    // Make sure operation did not fail
    if (!file) {
      std::cerr << "Could not open the file " << filename
        << " in reading mode" << std::endl;
      return;   // Let's do nothing anymore
    }

    // Read the words from the file and store them in the wordlist
    std::string line;
    while (getline(file, line)) {
      words->add(line);
    }

    // Close the file
    file.close();
  }

};