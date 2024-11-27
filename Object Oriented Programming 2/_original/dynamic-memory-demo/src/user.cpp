#include "user.h"

namespace Vives {
  User::User(std::string firstname, std::string lastname) {
    this->firstname = firstname;
    this->lastname = lastname;
  }

  void User::study_percentage(unsigned int percentage) {
    if (percentage > 100) percentage = 100;
    this->studyPercentage = percentage;
  }

  unsigned int User::study_percentage(void) const {
    return studyPercentage;
  }

  std::string User::to_string(void) const {
    return firstname + " " + lastname + ": "
      + "[" + std::to_string(study_percentage())
      + "%]";
  }

};