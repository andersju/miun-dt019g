/**
 * @file    person.h
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Headerfil för klassen Person
 */
#ifndef ANJE_PERSON_H
#define ANJE_PERSON_H

#include "address.h"
#include "name.h"
#include <iostream>
#include <string>
#include <vector>

/*
 * Klass för att hantera en person
 */
class Person {
private:
  Name name_;
  Address address_;
  std::string persnr_;
  int shoenr_;

public:
  Person();
  Person(const Name& name, const Address& address, const std::string& persNr, int shoenr);

  Name getName() const;
  Address getAddress() const;
  std::string getPersnr() const;
  int getShoenr() const;

  void setName(const Name& name);
  void setAddress(const Address& address);
  void setPersnr(const std::string& persnr);
  void setShoenr(int shoenr);

  // Överlagringar
  bool operator<(const Person& person) const;
  bool operator==(const Person& person) const;
};

// Överlagringar
std::ostream& operator<<(std::ostream& os, const Person& person);
std::istream& operator>>(std::istream& is, Person& person);

// Separata hjälpfunktioner
void showPersonHeader();
void showPerson(const Person& p);

#endif
