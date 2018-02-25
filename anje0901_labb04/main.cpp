/**
 * @file    main.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-02-10
 * @version 1.0
 * @brief   Program för att testa effektiviteten av quicksort/insertionsort/selectionsort/bubblesort
 *
 * Testat med g++ -O3 -Wall -Werror -Wextra -Wpedantic -Wconversion -std=c++11
 * och Visual Studio 2017
 */

#include "Timer.h"
#include "intarray.h"

#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using SortFunction = std::function<void(IntArray&, int)>;
using FunctionMap = std::map<std::string, SortFunction>;

void printHeader();
void printFooter(const std::string& kResultsFile);

int main() {
  const FunctionMap kAlgoMap{{"Bubblesort", &IntArray::bubbleSort},
                             {"Insertionsort", &IntArray::insertionSort},
                             {"Quicksort", &IntArray::quickSort},
                             {"Selectionsort", &IntArray::selectionSort}};
  const std::vector<int> kArraySizes = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000};
  const int kIterations = 10;
  const std::string kResultsFile = "results.csv";

  printHeader();

  std::ofstream outFile(kResultsFile);
  if (outFile.is_open()) {
    // Går igenom en algoritm i taget; kv.first är algoritmnamn, kv.second är funktionen
    for (const auto& kv : kAlgoMap) {
      // Går igenom en arraystorlek i taget
      for (const auto& arraySize : kArraySizes) {
        std::cout << std::left << std::setw(7) << arraySize;
        std::cout << std::setw(15) << kv.first << std::flush;

        IntArray intarray(arraySize);
        double time = 0;

        for (int i = 0; i < kIterations; ++i) {
          intarray.fillWithRandom();
          Timer timer{};
          timer.start();
          kv.second(intarray, arraySize);
          time += timer.stop();
        }

        std::cout << std::fixed << std::setprecision(2) << std::setw(11)
                  << time / kIterations / 1000;
        std::cout << std::setprecision(2) << time / 1000 << std::endl;
        // Skriver algoritmnamn, arraystorlek och tid i millisekunder till fil
        outFile << kv.first << "\t" << arraySize << "\t" << std::fixed << std::setprecision(2)
                << time / kIterations / 1000 << std::endl;
      }
      std::cout << std::endl;
    }
    outFile.close();
    printFooter(kResultsFile);
  } else {
    std::cout << "Could not open " << kResultsFile << " for writing." << std::endl;
  }
  return 0;
}

/*
 * En ko som är pepp på algoritmer
 */
void printHeader() {
  std::cout << R"( _____________________________  )" << std::endl;
  std::cout << R"(< Let's test some algorithms! > )" << std::endl;
  std::cout << R"( -----------------------------  )" << std::endl;
  std::cout << R"(        \   ^__^                )" << std::endl;
  std::cout << R"(         \  (oo)\_______        )" << std::endl;
  std::cout << R"(            (__)\       )\/\    )" << std::endl;
  std::cout << R"(                ||----w |       )" << std::endl;
  std::cout << R"(                ||     ||       )" << std::endl;
  std::cout << std::endl;
  std::cout << std::left << std::setw(7) << "Size" << std::setw(15);
  std::cout << "Algorithm" << std::setw(11) << "Avg. (ms)";
  std::cout << "Total (ms)" << std::endl;
  std::cout << std::string(43, '-') << std::endl;
}

/*
 * En hjälpsam anka
 */
void printFooter(const std::string& kResultsFile) {
  std::cout << R"( _______________________________________)" << std::endl;
  std::cout << "< Done! Results written to " << kResultsFile << "! >" << std::endl;
  std::cout << R"( ---------------------------------------)" << std::endl;
  std::cout << R"( \            )" << std::endl;
  std::cout << R"(  \           )" << std::endl;
  std::cout << R"(   \ >()_     )" << std::endl;
  std::cout << R"(      (__)__ _)" << std::endl;
}
