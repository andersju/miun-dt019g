/**
 * @file    personlist.h
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-02-09
 * @version 1.0
 * @brief   Headerfil för klassen PersonList
 */
#ifndef ANJE_PERSONLIST_H
#define ANJE_PERSONLIST_H

#include "person.h"
#include <string>
#include <vector>

/*
 * Klass för att hantera en lista med personer
 */
class PersonList {
private:
  std::vector<Person> personvector_;
  std::string filename_;

public:
  PersonList() = default;

  std::string getFilename() const { return filename_; }
  void setFilename(const std::string& filename) { filename_ = filename; }

  void addPerson(Person person);
  std::tuple<bool, Person> getPerson(int index) const;

  size_t size() { return personvector_.size(); } // Antal personer i listan

  void sortName();
  void sortPersnr();
  void sortShoenr();

  int readFromFile();
  int writeToFile();
};

#endif
