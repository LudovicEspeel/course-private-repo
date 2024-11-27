#include "string_helper.h"

namespace WordBlasterTheGame {

  bool StringHelper::is_valid_number(std::string value) {
    if (value.length() == 0) return false;

    for (auto && letter : value) {
      if (!isdigit(letter)) {
        return false;
      }
    }
    return true;
  }

  bool StringHelper::try_to_parse_number(std::string value, int * number) {
    if (is_valid_number(value)) {
      *number = stoi(value);
      return true;
    }
    return false;
  }

  std::string StringHelper::generate_single_character_string(char character, unsigned int length) {
    std::string output = "";
    for (unsigned int i = 0; i < length; i++) {
      output += character;
    }
    return output;
  }

  int StringHelper::index_of_space_before(std::string text, unsigned int index) {
    if (index < text.length()) {
      while (index >= 0 && text[index] != ' ') {
        index--;
      }
      return index;
    }
    return -1;
  }

  std::string StringHelper::center_text(std::string text, unsigned int boundaryLength) {
    if (boundaryLength > text.length()) {
      unsigned int leftOverSpace = boundaryLength - text.length();
      unsigned int leftSideSpaces = leftOverSpace / 2;
      unsigned int rightSideSpaces = (leftOverSpace / 2) + (leftOverSpace % 2);

      text = StringHelper::generate_single_character_string(' ', leftSideSpaces)
        + text + StringHelper::generate_single_character_string(' ', rightSideSpaces);
    }
    return text;
  }

  std::vector<std::string> StringHelper::wrap_text(std::string text, unsigned int wrapLength) {
    std::vector<std::string> output;

    do {
      unsigned int whereToCut = text.length();
      if (text.length() > wrapLength) {
        whereToCut = StringHelper::index_of_space_before(text, wrapLength);
        output.push_back(text.substr(0, whereToCut));
        text = text.substr(whereToCut+1, text.length()-(whereToCut+1));
      } else {
        output.push_back(text);
        text = "";
      }
    } while (text.length() > 0);
  
    return output;
  }

  std::string StringHelper::pad_text(std::string text, unsigned int totalLength, char character, bool padAtBack) {
    for (unsigned int i = text.length(); i < totalLength; i++ ) {
      if (padAtBack) {
        text += character;
      } else {
        text = character + text;
      }
    }
    return text;
  }

};
