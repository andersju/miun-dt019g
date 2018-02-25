/**
 * @file    person.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Implementationsfil för klassen Person
 */
#include "person.h"
#include "constants.h"
#include "userinterface.h"
#include <iomanip>
#include <iostream>

// Default-konstruktor
Person::Person() : name_{"", ""}, address_{"", "", ""}, persnr_(""), shoenr_(0) {}

// Initieringskonstruktor
Person::Person(const Name& name, const Address& address, const std::string& persnr, int shoenr)
    : name_(name), address_(address), persnr_(persnr), shoenr_(shoenr) {}

Name Person::getName() const { return name_; }

Address Person::getAddress() const { return address_; }

std::string Person::getPersnr() const { return persnr_; }

int Person::getShoenr() const { return shoenr_; }

void Person::setName(const Name& name) { name_ = name; }

void Person::setAddress(const Address& address) { address_ = address; }

void Person::setPersnr(const std::string& persnr) { persnr_ = persnr; }

void Person::setShoenr(int shoenr) { shoenr_ = shoenr; }

// För skrivning till fil
std::ostream& operator<<(std::ostream& os, const Person& person) {
  os << person.getName() << DELIM << person.getAddress() << DELIM << person.getPersnr() << DELIM
     << person.getShoenr() << std::endl;
  return os;
}

// För inläsning från fil
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

// Sorterar på i första hand namn, i andra hand adress
bool Person::operator<(const Person& person) const {
  // Jämför i första hand namn, i andra hand address. Dvs, läses som
  // OM namnen är identiska, returnera address_< person.getAddress(), annars
  // returnera name_ < person.getName()
  return name_ == person.getName() ? address_ < person.getAddress() : name_ < person.getName();
}

// Två personer är identiska om både namn och adress är lika
bool Person::operator==(const Person& person) const {
  return name_ == person.getName() && address_ == person.getAddress() &&
         persnr_ == person.getPersnr() && shoenr_ == person.getShoenr();
}

// Skriver ut tabellhuvudet med kolumnnamnen
void showPersonHeader() {
  std::cout << std::left << std::setw(20) << "Name";
  std::cout << std::setw(15) << "Street adress";
  std::cout << std::setw(8) << "Postal";
  std::cout << std::setw(12) << "City";
  std::cout << std::setw(12) << "Personal #";
  std::cout << std::setw(6) << "Shoe #" << std::endl;
  std::cout << std::string(73, '-') << std::endl;
}

// Skriver ut angiven person på prydligt vis
void showPerson(const Person& p) {
  std::cout << std::left << std::setw(20)
            << p.getName().getLastName() + ", " + p.getName().getFirstName();
  std::cout << std::setw(15) << p.getAddress().getStreetAddress();
  std::cout << std::setw(8) << p.getAddress().getPostalCode();
  std::cout << std::setw(12) << p.getAddress().getCity();
  std::cout << std::setw(12) << p.getPersnr();
  std::cout << std::right << std::setw(6) << p.getShoenr() << std::endl;
}
