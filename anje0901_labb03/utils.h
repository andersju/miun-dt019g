/**
 * @file    utils.h
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-02-09
 * @version 1.0
 * @brief   Funktionsprototyper för hjälpfunktioner
 */
#ifndef ANJE_UTILS_H
#define ANJE_UTILS_H

#include <string>

std::string getStringFromInput(const std::string& messageString, bool acceptEmpty = false);
int getIntFromInput(const std::string& messageString, bool acceptEmpty = false,
                    bool checkRange = false, int validFrom = 0, int validTo = 0);
void stringToLower(std::string& string);
void pauseProgram();
void clearScreen();

#endif