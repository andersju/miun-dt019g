/**
 * @file    functions.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-26
 * @version 1.0
 * @brief   Implementation av diverse hjälpfunktioner
 */
#include "functions.h"
#include <iostream>
#include <sstream>

void showMenu() {
  std::cout << "MENU" << std::endl;
  std::cout << std::string(20, '=') << std::endl;
  std::cout << "1. Add person" << std::endl;
  std::cout << "2. Show all persons" << std::endl;
  std::cout << "3. Exit" << std::endl;
  std::cout << std::string(20, '=') << std::endl;
}

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

void pauseProgram() {
  std::cout << "\nPress Enter to continue.";
  std::string str;
  std::getline(std::cin, str);
}

int getIntFromInput(const std::string& messageString, bool acceptEmpty, bool checkRange,
                    int validFrom, int validTo) {
  int result = 0;

  while (true) {
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
