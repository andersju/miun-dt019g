/**
 * @file    functions.h
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Diverse hjälpfunktioner
 */
#ifndef ANJE_FUNCTIONS_H
#define ANJE_FUNCTIONS_H

#include <string>

/*
 * Skriver ut menyn
 */
void showMenu();

/*
 * Rensar skärmen
 */
void clearScreen();

/*
 * Pausar programmet tills Enter trycks ned
 */
void pauseProgram();

/*
 * Ber om och hämtar heltal från användaren
 *
 * @param messageString Dialogtext att visa före input
 * @param acceptEmpty Acceptera tomt input (returnerar då 0)
 * @param checkRange Huruvida input måste vara inom ett visst intervall
 * @param validFrom Minsta accepterat värde (om checkRange är sant)
 * @param validTo Högsta accepterat värde (om checkRange är sant)
 * @return Inmatat heltal
 */
int getIntFromInput(const std::string& messageString, bool acceptEmpty = false,
                    bool checkRange = false, int validFrom = 0, int validTo = 0);

/*
 * Ber om och hämtar sträng från användaren
 *
 * @param messageString Dialogtext att visa före input
 * @param acceptEmpty Huruvida tom sträng ska accepteras som input
 * @return Inmatad sträng
 */
std::string getStringFromInput(const std::string& messageString, bool acceptEmpty = false);

#endif
