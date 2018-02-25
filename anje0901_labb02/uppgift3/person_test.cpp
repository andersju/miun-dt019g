/**
 * @file    person_test.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Program för att testa Person-klassen
 */
#include "functions.h"
#include "person.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<Person> persons{
      Person(Name("Foo", "Bar"), Address("Foogatan 23", "11540", "Stockholm"), "890214-4350", 45),
      Person(Name("Johnny", "Thunders"), Address("Blixtgatan 2", "91230", "Jokkmokk"),
             "520715-0520", 45),
      Person(Name("Samus", "Aran"), Address("Storgatan 1", "45220", "Kungsbacka"), "840320-3240",
             45),
  };

  while (true) {
    showMenu();
    int choice = getIntFromInput("Choose an option (1-3): ", false, true, 1, 3);
    clearScreen();

    switch (choice) {
    case 1:
      addPerson(persons);
      break;
    case 2:
      showPersons(persons);
      break;
    case 3:
      return 0;
    default:
      break;
    }

    pauseProgram();
    clearScreen();
  }
}