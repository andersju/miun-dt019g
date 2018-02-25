/**
 * @file    main.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-02-09
 * @version 1.0
 * @brief   Program för att hantera ett personregister (DT019G laboration 3)
 *
 * Testat med g++ -Wall -Werror -Wextra -Wpedantic -Wconversion -std=c++11
 * och Visual Studio 2017
 */
#include "userinterface.h"

int main() {
  UserInterface userinterface;
  userinterface.run();
  return 0;
}
