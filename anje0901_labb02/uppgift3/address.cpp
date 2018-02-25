/**
 * @file    address.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Implementationsfil för klassen Address
 */

#include "address.h"
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
