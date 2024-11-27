#pragma once

#include <string>
#include <vector>

namespace WordBlasterTheGame {

  class StringHelper {

    public:
      /**
       * Checks if the string value contains a valid number
       * that only contains digits.
       * 
       * @param value: a string containing a possible number
       *
       * @returns true if the string value contains a valid
       * number consisting of digits.
       */
      static bool is_valid_number(std::string value);

      /**
       * Try to parse the string value as a number. If its value the
       * result is stored in number and the method returns true.
       * 
       * @param value: a string containing a possible number
       * @param number: a pointer to an integer where the result
       * can be stored
       * 
       * @returns true if value contained a valid number and the result
       * was placed in number.
       */
      static bool try_to_parse_number(std::string value, int * number);

      /**
       * Generate a string of single characters.
       * 
       * @param character: the character to use to fill the string with
       * @param length: the number of characters that should be placed in the string
       * 
       * @returns the result of the single character string
       * containing length number of characters.
       */
      static std::string generate_single_character_string(char character, unsigned int length);

      /**
       * Find the space before the given index. The text is traversed from index
       * towards the front to search for a space character.
       * 
       * @param text: the text to search for the space
       * @param index: the index (included) from where the search should
       * take place
       * 
       * @returns the index of the first space found or -1 if none was found.
       */
      static int index_of_space_before(std::string text, unsigned int index);

      /**
       * Center a text by padding spaces left and right to fit in the boundary length,
       * 
       * @param text: the text to center
       * @param boundaryLength: the number of available characters in which the
       * text needs to be centered.
       *
       * @returns the centered text inside the boundary length
       */
      static std::string center_text(std::string text, unsigned int boundaryLength);

      /**
       * Split sentence into sections so each section should fit in the given wrapLength.
       *
       * @param text: the text to cut into sections
       * @param wrapLength: the maximum length of a section
       * 
       * @returns an std::vector of std::string objects where each string represents a
       * section of the text wrapped to fit the wrap length
       */
      static std::vector<std::string> wrap_text(std::string text, unsigned int wrapLength);

      /**
       * Add padding to a string at the front or back.
       * 
       * @param text: the original text that needs to be padded
       * @param totalLength: the length to which the text should be padded
       * @param character: the character to use as padding
       * @param padAtBack: if set to true the padding is done at the back of text,
       * otherwise the padding is done in front.
       */
      static std::string pad_text(std::string text, unsigned int totalLength, char character=' ', bool padAtBack=true);
  };

};