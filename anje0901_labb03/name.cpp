/**
 * @file    name.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Implementationsfil för klassen Name
 */
#include "name.h"
#include "constants.h"
#include "utils.h"
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

// Överlagring för inläsning från fil
std::ostream& operator<<(std::ostream& os, const Name& name) {
  os << name.getFirstName() << DELIM << name.getLastName();
  return os;
}

// Överlagring för utskrift till fil
std::istream& operator>>(std::istream& is, Name& name) {
  std::string tmpString;

  std::getline(is, tmpString, DELIM);
  name.setFirstName(tmpString);

  std::getline(is, tmpString, DELIM);
  name.setLastName(tmpString);

  return is;
}

// För sortering av namn. Omvandlar till lowercase först.
bool Name::operator<(const Name& name) const {
  std::string name1, name2;
  // Genom att slå ihop dem på formen "efternamnförnamn" jämförs i
  // första hand efternamn, i andra hand förnamn
  name1 = lastName_ + firstName_;
  name2 = name.getLastName() + name.getFirstName();

  stringToLower(name1);
  stringToLower(name2);

  return name1 < name2;
}

// Kollar om två namn är identiska. Omvandlar till lowercase först.
bool Name::operator==(const Name& name) const {
  std::string name1, name2;
  name1 = lastName_ + firstName_;
  name2 = name.getLastName() + name.getFirstName();

  stringToLower(name1);
  stringToLower(name2);

  return name1 == name2;
}
