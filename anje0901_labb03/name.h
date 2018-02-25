/**
 * @file    name.h
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Headerfil för klassen Name
 */
#ifndef ANJE_NAME_H
#define ANJE_NAME_H

#include <string>

/*
 * Klass för att hantera förnamn och efternamn
 */
class Name {
private:
  std::string firstName_;
  std::string lastName_;

public:
  Name();
  Name(const std::string& firstName, const std::string& lastName);

  std::string getFirstName() const;
  std::string getLastName() const;

  void setFirstName(const std::string& firstName);
  void setLastName(const std::string& lastName);

  // Överlagringar
  bool operator<(const Name& name) const;
  bool operator==(const Name& name) const;
};

// Överlagringar
std::ostream& operator<<(std::ostream& os, const Name& name);
std::istream& operator>>(std::istream& is, Name& name);

#endif
