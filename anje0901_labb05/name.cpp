/**
 * @file    name.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Implementationsfil för klassen Name
 */
#include "name.h"
#include "constants.h"
#include <algorithm>
#include <ostream>
#include <string>

// Default-konstruktor
Name::Name() : firstName_(""), lastName_("") {}

// Initieringskonstruktor
Name::Name(const std::string& firstName, const std::string& lastName)
    : firstName_(firstName), lastName_(lastName) {}

std::string Name::getFirstName() const { return firstName_; }

std::string Name::getLastName() const { return lastName_; }

void Name::setFirstName(const std::string& firstName) { firstName_ = firstName; }

void Name::setLastName(const std::string& lastName) { lastName_ = lastName; }

std::ostream& operator<<(std::ostream& os, const Name& name) {
  os << name.getFirstName() << DELIM << name.getLastName();
  return os;
}

std::istream& operator>>(std::istream& is, Name& name) {
  std::string tmpString;

  std::getline(is, tmpString, DELIM);
  name.setFirstName(tmpString);

  std::getline(is, tmpString, DELIM);
  name.setLastName(tmpString);

  return is;
}

bool Name::operator<(const Name& name) const {
  std::string name1 = lastName_ + " " + firstName_;
  std::string name2 = name.getLastName() + " " + name.getFirstName();

  std::transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
  std::transform(name2.begin(), name2.end(), name2.begin(), ::tolower);

  return name1 < name2;
}

bool Name::operator==(const Name& name) const {
  std::string name1 = lastName_ + " " + firstName_;
  std::string name2 = name.getLastName() + " " + name.getFirstName();

  std::transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
  std::transform(name2.begin(), name2.end(), name2.begin(), ::tolower);

  return name1 == name2;
}
