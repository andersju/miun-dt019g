/**
 * @file    userinterface.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-02-09
 * @version 1.0
 * @brief   Implementationsfil för klassen UserInterface
 */
#include "userinterface.h"
#include "person.h"
#include "utils.h"
#include <iostream>
#include <sstream>
#include <tuple>

void UserInterface::run() { showMenu(); }

int UserInterface::showMenu() {
  while (true) {
    // figlet -f slant "menu"
    std::cout << R"(   ____ ___  ___  ____  __  __ )" << std::endl;
    std::cout << R"(  / __ `__ \/ _ \/ __ \/ / / / )" << std::endl;
    std::cout << R"( / / / / / /  __/ / / / /_/ /  )" << std::endl;
    std::cout << R"(/_/ /_/ /_/\___/_/ /_/\__,_/ )" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Add person" << std::endl;
    std::cout << "2. Show all persons" << std::endl;
    std::cout << "3. Save to file" << std::endl;
    std::cout << "4. Read from file" << std::endl;
    std::cout << "5. Sort by name (ascending)" << std::endl;
    std::cout << "6. Sort by personal number (descending)" << std::endl;
    std::cout << "7. Sort by shoe size (descending)" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << std::string(20, '=') << std::endl;

    int choice = getIntFromInput("Choose an option (1-8): ", false, true, 1, 8);
    clearScreen();

    switch (choice) {
    case 1:
      addPerson();
      break;
    case 2:
      showPersons();
      break;
    case 3:
      writeToFile();
      break;
    case 4:
      readFromFile();
      break;
    case 5:
      sortName();
      break;
    case 6:
      sortPersnr();
      break;
    case 7:
      sortShoenr();
      break;
    case 8:
      return 0;
    default:
      break;
    }

    pauseProgram();
    clearScreen();
  }
}

void UserInterface::addPerson() {
  std::cout << "Add person" << std::endl;

  std::string firstName = getStringFromInput("Enter first name: ");
  std::string lastName = getStringFromInput("Enter last name: ");
  std::string streetAddress = getStringFromInput("Enter street address: ");
  std::string postalCode = getStringFromInput("Enter postal code: ");
  std::string city = getStringFromInput("Enter city: ");
  std::string personNr = getStringFromInput("Enter personal number: ");
  int skoNr = getIntFromInput("Enter shoe size: ");

  personlist_.addPerson(
      Person(Name(firstName, lastName), Address(streetAddress, postalCode, city), personNr, skoNr));
}

void UserInterface::showPersons() {
  showPersonHeader();
  for (int i = 0; i < (int)personlist_.size(); ++i) {
    bool status;
    Person person;
    std::tie(status, person) = personlist_.getPerson(i);

    if (status) {
      showPerson(person);
    }
  }
}

void UserInterface::writeToFile() {
  std::string filename = getStringFromInput("Enter filename to save to: ");
  personlist_.setFilename(filename);

  if (personlist_.writeToFile() == 0) {
    std::cout << personlist_.size() << " persons successfully written to " << filename << std::endl;
  } else {
    std::cout << "Could not open " << filename << " for writing." << std::endl;
  }
}

void UserInterface::readFromFile() {
  std::string filename = getStringFromInput("Enter filename to read from: ");
  personlist_.setFilename(filename);

  if (personlist_.readFromFile() == 0)
    std::cout << personlist_.size() << " persons successfully loaded from " << filename
              << std::endl;
  else {
    std::cout << "Couldn't open " << filename << " for reading." << std::endl;
  }
}

void UserInterface::sortName() {
  std::cout << "Sorting by name" << std::endl;
  personlist_.sortName();
}

void UserInterface::sortPersnr() {
  std::cout << "Sorting by personal number" << std::endl;
  personlist_.sortPersnr();
}

void UserInterface::sortShoenr() {
  std::cout << "Sorting by shoe size" << std::endl;
  personlist_.sortShoenr();
}
