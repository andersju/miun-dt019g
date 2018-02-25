/**
 * @file    labb01_uppgift01.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-01-23
 * @version 1.0
 * @brief   Skapar dynamisk array av int:ar med slumpmässiga tal; använder pekare för att skriva ut
 * och beräkna min/max/summa
 *
 * Provat med GCC/G++ 7.2.0:
 * g++ -Wall -Wextra -Werror -Wpedantic -Wconversion -std=c++11 labb01_uppgift01.cpp -o program
 * samt med Visual Studio 2017
 */
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>

int main() {
  // Skapar slumptalsgenerator
  std::random_device randomDevice;
  // Använder Mersenne Twister 19937-slumptalsmotorn
  std::mt19937 randomNumberGenerator(randomDevice());
  // Slumpar fram int:ar inom angivet intervall
  std::uniform_int_distribution<int> distribution(-5000, 5000);

  int numberOfElements = 0;
  std::cout << "Enter number of elements in array plz (positive integer): ";
  std::cin >> numberOfElements;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (std::cin.fail() || numberOfElements <= 0) {
    std::cout << "You failed to enter a positive integer. NO array for you. Goodbye." << std::endl;
    return 0;
  }

  // Allokerar plats för en array av angiven storlek
  int* randomArray = new int[numberOfElements];
  // Pekare till sista elementet i arrayen
  int* randomArrayEnd = randomArray + numberOfElements;

  // Fyller arrayen med slumpmässiga tal och skriver ut dem
  int counter = 1;
  for (int* p = randomArray; p != randomArrayEnd; ++p) {
    *p = distribution(randomNumberGenerator);
    std::cout << std::setw(7) << *p;

    // Skriver ut 10 per rad
    if (counter % 10 == 0 || p == randomArrayEnd - 1)
      std::cout << std::endl;

    // Skriver ut 200 i taget
    if (counter % 200 == 0 && p != randomArrayEnd - 1) {
      std::cout << "\nPress Enter to see more numbers..." << std::endl;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    ++counter;
  }

  // minValue och maxValue pekar initialt på arrayens första element
  int* minValue = randomArray;
  int* maxValue = randomArray;
  int sum = 0;
  // Loopar igenom arrayen med hjälp av pekare
  for (int* p = randomArray; p != randomArrayEnd; ++p) {
    // Låter minValue peka på p OM värdet som p pekar på är mindre än värdet minValue pekar på
    if (*p < *minValue)
      minValue = p;
    // ...samt det omvända för maxvärdet
    if (*p > *maxValue)
      maxValue = p;
    // Addera värdet som p pekar på till summeringsvariabeln
    sum += *p;
  }

  std::cout << "Lowest value : " << *minValue << std::endl;
  std::cout << "Highest value: " << *maxValue << std::endl;
  std::cout << "Sum of values: " << sum << std::endl;

  // Frigör det utrymme som randomArray använder
  delete[] randomArray;

  return 0;
}
