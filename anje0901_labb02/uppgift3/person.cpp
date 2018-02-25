/**
 * @file    person.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Implementationsfil för klassen Person
 */
#include "person.h"
#include "functions.h"
#include <iomanip>
#include <iostream>

// Default-konstruktor
Person::Person() : name_{"", ""}, address_{"", "", ""}, persNr_(""), skoNr_(0) {}

// Initieringskonstruktor
Person::Person(const Name& name, const Address& address, const std::string& persNr, int skoNr)
    : name_(name), address_(address), persNr_(persNr), skoNr_(skoNr) {}

Name Person::getName() const { return name_; }

Address Person::getAddress() const { return address_; }

std::string Person::getPersNr() const { return persNr_; }

int Person::getSkoNr() const { return skoNr_; }

void Person::setName(const Name& name) { name_ = name; }

void Person::setAddress(const Address& address) { address_ = address; }

void Person::setPersNr(const std::string& persNr) { persNr_ = persNr; }

void Person::setSkoNr(int skoNr) { skoNr_ = skoNr; }

void addPerson(std::vector<Person>& persons) {
  std::cout << "Add person" << std::endl;

  std::string firstName = getStringFromInput("Enter first name: ");
  std::string lastName = getStringFromInput("Enter last name: ");
  std::string streetAddress = getStringFromInput("Enter street address: ");
  std::string postalCode = getStringFromInput("Enter postal code: ");
  std::string city = getStringFromInput("Enter city: ");
  std::string personNr = getStringFromInput("Enter personal number: ");
  int skoNr = getIntFromInput("Enter shoe size: ");

  /* Skulle alternativt kunnat göra så här:
   * Person p;
   * Name n;
   * Address a;
   * n.setFirstName("Blorgh");
   * ...osv..
   * och sen p.setName(n); p.setAddress(a); persons.emplace_back(p);
   * ...men nedanstående känns smidigare
   */
  persons.emplace_back(
      Person(Name(firstName, lastName), Address(streetAddress, postalCode, city), personNr, skoNr));
}

void showPersons(const std::vector<Person>& persons) {
  std::cout << std::left << std::setw(20) << "Name";
  std::cout << std::setw(15) << "Street adress";
  std::cout << std::setw(8) << "Postal";
  std::cout << std::setw(12) << "City";
  std::cout << std::setw(12) << "Personal #";
  std::cout << std::setw(6) << "Shoe #" << std::endl;
  for (const auto& p : persons) {
    showPerson(p);
  }
}

void showPerson(const Person& p) {
  std::cout << std::left << std::setw(20)
            << p.getName().getFirstName() + " " + p.getName().getLastName();
  std::cout << std::setw(15) << p.getAddress().getStreetAddress();
  std::cout << std::setw(8) << p.getAddress().getPostalCode();
  std::cout << std::setw(12) << p.getAddress().getCity();
  std::cout << std::setw(12) << p.getPersNr();
  std::cout << std::setw(6) << p.getSkoNr() << std::endl;
}
