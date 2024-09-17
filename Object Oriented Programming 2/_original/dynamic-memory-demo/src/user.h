#pragma once

#include <string>

// #############
// # User
// #############
// # - firstname: string
// # - lastname: string
// # - studyPercentage: uint [0, 100]
// ############################
// # + User(fn: string, ln: string)
// # + study_percentage(percentage: uint)
// # + study_percentage(): uint
// # + to_string(): string
// #############################

namespace Vives {

  class User {
    public:
      User(std::string firstname, std::string lastname);

    public:
      void study_percentage(unsigned int percentage);
      unsigned int study_percentage(void) const;

    public:
      std::string to_string(void) const;

    private:
      std::string firstname = "";
      std::string lastname = "";
      unsigned int studyPercentage = 0;
  };

};