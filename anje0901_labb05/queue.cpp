/**
 * @file    queue.cpp
 * @author  Anders Jensen-Urstad (anje0901) <anders@unix.se>
 * @date    2018-02-20
 * @version 1.0
 * @brief   Implementationsfil för klasserna Node, QIterator och QList
 */

#include "queue.h"

class Node {
public:
  Node* next;
  Item data;

  Node(Node* n, Item newData) : next(n), data(newData) {}
};

QIterator::QIterator() { node = nullptr; }

QIterator::QIterator(Node* n) { node = n; }

Item& QIterator::operator*() const { return node->data; }

// Prefix
QIterator& QIterator::operator++() {
  node = node->next;
  return *this;
}

// Postfix
QIterator QIterator::operator++(int) {
  QIterator tmpNode = *this;
  node = node->next;
  return tmpNode;
}

bool QIterator::operator!=(const QIterator& qi) const { return node != qi.node; }

QList::~QList() {
  while (!isEmpty()) {
    Node* tmpNode = first;
    first = first->next;
    delete tmpNode;
  }
}

/*
 * Lägger till Item i slutet av kön
 */
void QList::enque(Item item) {
  Node* newNode = new Node(nullptr, item);

  if (isEmpty())
    first = newNode;
  else
    last->next = newNode;

  last = newNode;
}

/*
 * Tar bort Item från början av kön
 */
bool QList::deque(Item& item) {
  if (isEmpty())
    return false;

  Node* n = first;
  item = n->data;
  first = first->next;

  // Om kön blev tom efter att item tagits bort måste last sättas till nullptr.
  if (isEmpty())
    last = nullptr;

  delete n;
  return true;
}

/*
 * Tar bort godycklig Item från kön
 */
bool QList::del(Item item) {
  if (isEmpty())
    return false;

  // Om item är först i listan (eller enda i listan) är det bara att köra deque.
  if (first->data == item) {
    deque(item);
    return true;
  }

  Node* tmpCurrent = first;
  // Annars, loopa igenom allt...
  while (tmpCurrent != nullptr) {
    // Om nästa nod är den efterfrågade...
    if (tmpCurrent->next->data == item) {
      Node* n = tmpCurrent->next;
      // Om nästa nod är sist...
      if (tmpCurrent->next == last) {
        // ...så sätt last till nuvarande nod, med nullptr som nästa.
        last = tmpCurrent;
        tmpCurrent->next = nullptr;
      } else {
        // I annat fall är nästa nod varken först eller sist,
        // så sätt nuvarande nods next till nästnästa.
        tmpCurrent->next = tmpCurrent->next->next;
      }
      delete n;
      return true;
    }
    tmpCurrent = tmpCurrent->next;
  }

  // Efterfrågad person hittades inte.
  return false;
}

bool QList::isEmpty() const { return first == nullptr; }
