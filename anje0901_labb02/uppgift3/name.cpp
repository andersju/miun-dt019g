/**
 * @file    name.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Implementationsfil för klassen Name
 */

#include "name.h"
#include <string>

// Default-konstruktor
Name::Name() : firstName_(""), lastName_("") {}

// Initieringskonstruktor
Name::Name(const std::string& firstName, const std::string& lastName)
    : firstName_(firstName), lastName_(lastName) {}

std::string Name::getFirstName() const { return firstName_; }

std::string Name::getLastName() const { return lastName_; }

void Name::setFirstName(const std::string& firstName) { firstName_ = firstName; }

void Name::setLastName(const std::string& lastName) { lastName_ = lastName; }
