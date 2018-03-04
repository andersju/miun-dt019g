/**
 * @file    address.h
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Headerfil för klassen Address
 */
#ifndef ANJE_ADDRESS_H
#define ANJE_ADDRESS_H

#include <string>

/*
 * Klass för att hantera gatuadress/postnummer/stad
 */
class Address {
private:
  std::string streetAddress_;
  std::string postalCode_;
  std::string city_;

public:
  Address();
  Address(const std::string& streetAddress, const std::string& postalCode, const std::string& city);

  std::string getStreetAddress() const;
  std::string getPostalCode() const;
  std::string getCity() const;

  void setStreetAddress(const std::string& streetAddress);
  void setPostalCode(const std::string& postalCode);
  void setCity(const std::string& city);

  bool operator<(const Address& address) const;
  bool operator==(const Address& address) const;
};

std::ostream& operator<<(std::ostream& os, const Address& address);
std::istream& operator>>(std::istream& is, Address& address);

#endif
