/**
 * @file    person.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Implementationsfil för klassen Person
 */

#include "constants.h"
#include "person.h"

#include <iomanip>
#include <iostream>

// Default-konstruktor
Person::Person() : name_{"", ""}, address_{"", "", ""}, persnr_(""), shoenr_(0) {}

// Initieringskonstruktor
Person::Person(const Name& name, const Address& address, const std::string& persnr, int shoenr)
    : name_(name), address_(address), persnr_(persnr), shoenr_(shoenr) {}

Name Person::getName() const {
  return name_;
}

Address Person::getAddress() const { return address_; }

std::string Person::getPersnr() const { return persnr_; }

int Person::getShoenr() const { return shoenr_; }

void Person::setName(const Name& name) { name_ = name; }

void Person::setAddress(const Address& address) { address_ = address; }

void Person::setPersnr(const std::string& persnr) { persnr_ = persnr; }

void Person::setShoenr(int shoenr) { shoenr_ = shoenr; }

void showPersonHeader() {
  std::cout << std::left << std::setw(20) << "Name";
  std::cout << std::setw(15) << "Street adress";
  std::cout << std::setw(8) << "Postal";
  std::cout << std::setw(12) << "City";
  std::cout << std::setw(12) << "Personal #";
  std::cout << std::setw(6) << "Shoe #" << std::endl;
}

void Person::showPerson(const Person& p) {
  std::cout << std::left << std::setw(20)
            << p.getName().getFirstName() + " " + p.getName().getLastName();
  std::cout << std::setw(15) << p.getAddress().getStreetAddress();
  std::cout << std::setw(8) << p.getAddress().getPostalCode();
  std::cout << std::setw(12) << p.getAddress().getCity();
  std::cout << std::setw(12) << p.getPersnr();
  std::cout << std::setw(6) << p.getShoenr() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
  os << person.getName() << DELIM << person.getAddress() << DELIM << person.getPersnr() << DELIM
     << person.getShoenr() << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Person& person) {
  Name name;
  Address address;
  std::string persnr;
  int shoenr;

  is >> name;
  person.setName(name);

  is >> address;
  person.setAddress(address);

  std::getline(is, persnr, DELIM);
  person.setPersnr(persnr);

  is >> shoenr;
  person.setShoenr(shoenr);

  is.get();
  return is;
}

bool Person::operator<(const Person& person) const {
  if (name_ == person.getName()) {
    return address_ < person.getAddress();
  } else {
    return name_ < person.getName();
  }
}

bool Person::operator==(const Person& person) const {
  return (name_ == person.getName()) && (address_ == person.getAddress());
}
