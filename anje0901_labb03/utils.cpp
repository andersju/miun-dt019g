/**
 * @file    utils.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-02-09
 * @version 1.0
 * @brief   Diverse små hjälpfunktioner
 */
#include "utils.h"
#include <algorithm>
#include <iostream>
#include <sstream>

/*
 * Pausar programmet tills Enter tryckts ner
 */
void pauseProgram() {
  std::cout << "\nPress Enter to continue.";
  std::string str;
  std::getline(std::cin, str);
}

/*
 * Hanterar input av heltal. Möjligt att ange att tomt input ska accepteras
 * och att en viss range ska användas.
 */
int getIntFromInput(const std::string& messageString, bool acceptEmpty, bool checkRange,
                    int validFrom, int validTo) {
  int result = 0;

  while (true) {
    // För att göra det enklare med felhantering läses input in som en sträng,
    // som sedan konverteras till int.
    std::string inputStr;
    std::cout << messageString;
    std::getline(std::cin, inputStr);

    if (!inputStr.empty()) {
      std::istringstream iss(inputStr);
      if (iss >> result) {
        if (!checkRange || (result >= validFrom && result <= validTo)) {
          return result;
        }
      }
    } else if (acceptEmpty) {
      return -1;
    }
  }
}

/*
 * Hanterar input av sträng. Möjligt att ange huruvida tom sträng ska accepteras.
 */
std::string getStringFromInput(const std::string& messageString, bool acceptEmpty) {
  while (true) {
    std::string inputString;
    std::cout << messageString;
    std::getline(std::cin, inputString);

    if (!inputString.empty() || acceptEmpty) {
      return inputString;
    }
  }
}

/*
 * Rensar skärmen
 */
void clearScreen() {
// Det finns inget standardsätt att rensa skärmen, så försök att göra det
// minst dåliga alternativet beroende på plattform.
#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
  std::cout << "\033[2J\033[1;1H" << std::endl;
#elif _WIN32
  system("cls");
#else
  std::cout << std::string(100, '\n') << std::endl;
#endif
}

/*
 * Gör sträng gemen
 */
void stringToLower(std::string& string) {
  std::transform(string.begin(), string.end(), string.begin(), ::tolower);
}
