/**
 * @file    queue.h
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-02-20
 * @version 1.0
 * @brief   Headerfil för klasserna Node, QIterator och QList
 */

#ifndef ANJE_QUEUE_H
#define ANJE_QUEUE_H

#include "person.h"

typedef Person Item;

class Node;

class QIterator {
private:
  Node* node;

public:
  QIterator();
  QIterator(Node* n);

  Item& operator*() const;
  QIterator& operator++(); // Prefix
  QIterator operator++(int); // Postfix
  bool operator!=(const QIterator& qi) const;
};

class QList {
private:
  Node *first, *last;

public:
  QList() : first(nullptr), last(nullptr){};
  ~QList();
  void enque(Item item);
  bool deque(Item& item);
  bool del(Item item);
  bool isEmpty() const;

  QIterator begin() const { return QIterator(first); }
  QIterator end() const { return QIterator(nullptr); }
};

#endif
