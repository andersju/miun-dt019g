/**
 * @file    address_test.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Program för att testa Address-klassen
 */

#include "address.h"
#include <iostream>

int main() {
  std::cout << "Creating address1 using default constructor..." << std::endl;
  Address address1;

  std::cout << "Setting street address, postal code and city for address1 using setters..."
            << std::endl;
  address1.setStreetAddress("Foogatan 23");
  address1.setPostalCode("11530");
  address1.setCity("Ankeborg");

  std::cout << "Printing street address, postal code and city using getters:" << std::endl;
  std::cout << address1.getStreetAddress() << ", " << address1.getPostalCode() << " "
            << address1.getCity() << std::endl;

  std::cout << "\nCreating address2 and setting values using initialization constructor..."
            << std::endl;
  Address address2{"221 Baker St.", "NW1 6XE", "London"};

  std::cout << "Printing street address, postal code and city using getters:" << std::endl;
  std::cout << address2.getStreetAddress() << ", " << address2.getPostalCode() << " "
            << address2.getCity() << std::endl;

  std::cout << "Changing city of address2 object..." << std::endl;
  address2.setCity("Waaaaaaaa");

  std::cout << "Printing street address, postal code and city using getters:" << std::endl;
  std::cout << address2.getStreetAddress() << ", " << address2.getPostalCode() << " "
            << address2.getCity() << std::endl;

  return 0;
}
