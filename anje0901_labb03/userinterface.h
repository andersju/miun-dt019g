/**
 * @file    userinterface.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-02-09
 * @version 1.0
 * @brief   Headerfil för klassen UserInterface
 */
#ifndef ANJE_USERINTERFACE_H
#define ANJE_USERINTERFACE_H

#include "personlist.h"
#include <string>
#include <vector>

/*
 * Klass som ger gränssnitt för att hantera PersonList-klassen
 */
class UserInterface {
private:
  PersonList personlist_;

  int showMenu();
  void addPerson();
  void showPersons();
  void writeToFile();
  void readFromFile();
  void sortName();
  void sortPersnr();
  void sortShoenr();

public:
  UserInterface() = default;
  void run();
};

#endif
