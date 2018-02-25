/**
 * @file    name_test.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Program för att testa Name-klassen
 */

#include "name.h"
#include <iostream>

int main() {
  std::cout << "Creating name1 using default constructor..." << std::endl;
  Name name1;

  std::cout << "Setting firstname and lastname for name1 using setters..." << std::endl;
  name1.setFirstName("Samus");
  name1.setLastName("Aran");

  std::cout << "Printing firstname and lastname of name1 using getters:" << std::endl;
  std::cout << name1.getFirstName() << " " << name1.getLastName() << std::endl;

  std::cout << "\nCreating name2 and setting values using initialization constructor..."
            << std::endl;
  Name name2{"Johnny", "Thunders"};

  std::cout << "Printing firstname and lastname of name2 using getters:" << std::endl;
  std::cout << name2.getFirstName() << " " << name2.getLastName() << std::endl;

  std::cout << "Changing firstname of name2 object..." << std::endl;
  name2.setFirstName("Johan");

  std::cout << "Printing firstname and lastname for name2 again using getters:" << std::endl;
  std::cout << name2.getFirstName() << " " << name2.getLastName() << std::endl;

  return 0;
}
