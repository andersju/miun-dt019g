/**
 * @file    personlist.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-02-09
 * @version 1.0
 * @brief   Implementationsfil för klassen PersonList
 */
#include "personlist.h"
#include "person.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <tuple>

void PersonList::addPerson(Person person) { personvector_.emplace_back(person); }

std::tuple<bool, Person> PersonList::getPerson(int index) const {
  // Eftersom index är size_t och size_t per definition är unsigned
  // (dvs kan inte vara negativt) behövs det inte kollas om index är > -1
  if (index >= 0 && index < (int)personvector_.size()) {
    return std::make_tuple(true, personvector_[index]);
  } else {
    return std::make_tuple(false, Person());
  }
}

int PersonList::writeToFile() {
  std::ofstream outFile(filename_);

  if (outFile.is_open()) {
    for (auto& e : personvector_) {
      outFile << e;
    }
    outFile.close();

    return 0;
  } else {
    return -1;
  }
}

int PersonList::readFromFile() {
  // Rensa vektorn om nödvändigt
  if (!personvector_.empty()) {
    personvector_.clear();
  }

  std::ifstream inFile(filename_);

  if (inFile.is_open()) {
    Person tmpPerson;

    // Använder överlagringen i Person
    while (inFile >> tmpPerson) {
      addPerson(tmpPerson);
    }
    inFile.close();

    return 0;
  } else {
    return -1;
  }
}

void PersonList::sortName() {
  // Sorteringsfunktion behövs inte här eftersom < är överlagrad i Person
  std::sort(personvector_.begin(), personvector_.end());
}

void PersonList::sortPersnr() {
  std::sort(personvector_.begin(), personvector_.end(),
            [](const Person& a, const Person& b) { return a.getPersnr() > b.getPersnr(); });
}

void PersonList::sortShoenr() {
  std::sort(personvector_.begin(), personvector_.end(),
            [](const Person& a, const Person& b) { return a.getShoenr() > b.getShoenr(); });
}
