/**
 * @file    intarray.h
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-02-10
 * @version 1.0
 * @brief   Headerfil för klassen IntArray
 */
#ifndef ANJE_INTARRAY_H
#define ANJE_INTARRAY_H

#include <cstddef>
#include <string>

class IntArray {
private:
  int* arr_;
  size_t size_;

public:
  IntArray();
  explicit IntArray(int pNum);
  ~IntArray();

  int getValue(int idx) const;
  void fillWithRandom();

  void quick1(int a[], int first, int last);
  void quickSort(int size);
  void insertionSort(int size);
  void selectionSort(int size);
  void bubbleSort(int size);
};

#endif
