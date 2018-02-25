/**
 * @file    address.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Implementationsfil för klassen Address
 */
#include "address.h"
#include "constants.h"
#include "utils.h"
#include <algorithm>
#include <ostream>
#include <string>

// Default-konstruktor
Address::Address() : streetAddress_(""), postalCode_(""), city_("") {}

// Med initieringskonstruktor
Address::Address(const std::string& streetAddress, const std::string& postalCode,
                 const std::string& city)
    : streetAddress_(streetAddress), postalCode_(postalCode), city_(city) {}

std::string Address::getStreetAddress() const { return streetAddress_; }

std::string Address::getPostalCode() const { return postalCode_; }

std::string Address::getCity() const { return city_; }

void Address::setStreetAddress(const std::string& streetAddress) { streetAddress_ = streetAddress; }

void Address::setPostalCode(const std::string& postalCode) { postalCode_ = postalCode; }

void Address::setCity(const std::string& city) { city_ = city; }

// Överlagring för inläsning från fil
std::ostream& operator<<(std::ostream& os, const Address& address) {
  os << address.getStreetAddress() << DELIM << address.getPostalCode() << DELIM
     << address.getCity();
  return os;
}

// Överlagring för utskrift till fil
std::istream& operator>>(std::istream& is, Address& address) {
  std::string tmpString;

  std::getline(is, tmpString, DELIM);
  address.setStreetAddress(tmpString);

  std::getline(is, tmpString, DELIM);
  address.setPostalCode(tmpString);

  std::getline(is, tmpString, DELIM);
  address.setCity(tmpString);

  return is;
}

// För sortering av adresser. Omvandlar till lowercase först.
bool Address::operator<(const Address& address) const {
  std::string address1, address2;
  // Jämför i första hand stad, i andra hand förnamn
  address1 = city_ + streetAddress_;
  address2 = address.getCity() + address.getStreetAddress();

  stringToLower(address1);
  stringToLower(address2);

  return address1 < address2;
}

// Kollar om två adresser är identiska. Omvandlar till lowercase först.
bool Address::operator==(const Address& address) const {
  std::string address1, address2;
  address1 = city_ + streetAddress_;
  address2 = address.getCity() + address.getStreetAddress();

  stringToLower(address1);
  stringToLower(address2);

  return address1 == address2;
}
