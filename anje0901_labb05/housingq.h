#ifndef ANJE_HOUSINGQ_H
#define ANJE_HOUSINGQ_H

#include "queue.h"

class HousingQ {
private:
  QList qlist_;
  int queueSize_; // Antal personer i kön
  std::string filename_;

  void setFilename(const std::string& filename) { filename_ = filename; }

  void addToQueue();
  void offerHousing();
  void printQueue();
  void printPerson();
  void removeFromQueue();
  void readQueueFromFile();
  void saveQueueToFile();

public:
  HousingQ();
  int run();
  int showMenu();
};

#endif
