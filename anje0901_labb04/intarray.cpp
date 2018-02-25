/**
 * @file    intarray.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-02-10
 * @version 1.0
 * @brief   Implementationsfil för klassen IntArray
 */

#include "intarray.h"

#include <algorithm>
#include <iostream>
#include <random>

IntArray::IntArray() : size_(0) { arr_ = nullptr; }

IntArray::IntArray(int size) : size_(size) { arr_ = new int[size]; }

IntArray::~IntArray() {
  delete[] arr_;
  arr_ = nullptr;
}

int IntArray::getValue(int idx) const { return arr_[idx]; }

void IntArray::fillWithRandom() {
  // Skapar slumptalsgenerator
  static std::random_device randomDevice;
  // Använder Mersenne Twister 19937-slumptalsmotorn
  static std::mt19937 randomNumberGenerator(randomDevice());
  // Slumpar fram int:ar inom angivet intervall
  std::uniform_int_distribution<int> distribution(0, (int)size_ - 1);

  for (int i = 0; i < (int)size_; ++i) {
    arr_[i] = distribution(randomNumberGenerator);
  }
}

// Från sort.cpp av Per Ekeroot
void IntArray::quick1(int a[], int first, int last) {
  if (first < last) {
    int low = first;
    int high = last;
    if (a[first] > a[last]) { // Place a sentinel in the position a[last ] !
      std::swap(a[first], a[last]);
    }
    do {
      // Gå från från början och sök första värdet som är större än a[first]
      do {
        low++;
      } while (a[low] < a[first]);

      // Gå från slutet och sök första värdet som är mindre än a[first]
      do {
        high--;
      } while (a[high] > a[first]);

      // Byt plats på a[low] och a[high] om low < high
      if (low < high) {
        std::swap(a[low], a[high]);
      }
    } while (low <= high); // Fortsätt tills low > high

    std::swap(a[first], a[high]); // Placera a[first] i sorterad position

    quick1(a, first, high - 1); // Sortera vänster dellista
    quick1(a, high + 1, last);  // Sortera höger dellista
  }
}

void IntArray::quickSort(int size) { quick1(arr_, 0, size - 1); }

// Från sort.cpp av Per Ekeroot
void IntArray::insertionSort(int size) {
  if (size > 1) {
    int save, j;
    for (int k = size - 1; k >= 0; k--) {
      j = k + 1;
      save = arr_[k];
      while (j < size && save > arr_[j]) {
        arr_[j - 1] = arr_[j];
        j++;
      }
      arr_[j - 1] = save;
    }
  }
}

// Från sort.cpp av Per Ekeroot
void IntArray::selectionSort(int size) {
  for (int i = 0; i < size - 1; i++) {
    int smallIdx = i;                    // Index för det minsta elementet till höger om pos i
    for (int j = i + 1; j < size; j++) { // Leta rätt på det minsta "osorterade" elementet
      if (arr_[j] < arr_[smallIdx]) {
        smallIdx = j; // Spara index för det minsta elementet
      }
    }
    if (smallIdx != i) { // Byt plats om det fanns något mindre än a[i]
      std::swap(arr_[i], arr_[smallIdx]);
    }
  }
}

// Från sort.cpp av Per Ekeroot
void IntArray::bubbleSort(int size) {
  // Jämför två värden parvis och std::swappar dem om nödvändigt.
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (arr_[i] > arr_[j]) {
        std::swap(arr_[i], arr_[j]);
      }
    }
  }
}
