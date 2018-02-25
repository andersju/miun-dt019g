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
#include <ostream>
#include <string>
#include <vector>

/*
 * Klass för att hantera en person
 */
class Person {
private:
  Name name_;
  Address address_;
  std::string persNr_;
  int skoNr_;

public:
  Person();
  Person(const Name& name, const Address& address, const std::string& persNr, int skoNr);

  Name getName() const;
  Address getAddress() const;
  std::string getPersNr() const;
  int getSkoNr() const;

  void setName(const Name& name);
  void setAddress(const Address& address);
  void setPersNr(const std::string& persNr);
  void setSkoNr(int skoNr);
};

void addPerson(std::vector<Person>& persons);
void showPersons(const std::vector<Person>& persons);
void showPerson(const Person& p);

#endif
