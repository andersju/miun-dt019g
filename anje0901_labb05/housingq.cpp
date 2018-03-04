#include "housingq.h"
#include "person.h"
#include "queue.h"
#include "utils.h"

#include <fstream>
#include <iomanip>
#include <iostream>

HousingQ::HousingQ() : queueSize_(0), filename_("") {}

int HousingQ::run() {
  std::string filename = getStringFromInput("Enter filename to use: ");
  setFilename(filename);
  readQueueFromFile();
  showMenu();

  return 0;
}

int HousingQ::showMenu() {
  while (true) {
    // figlet -f slant "menu"
    std::cout << R"(   ____ ___  ___  ____  __  __ )" << std::endl;
    std::cout << R"(  / __ `__ \/ _ \/ __ \/ / / / )" << std::endl;
    std::cout << R"( / / / / / /  __/ / / / /_/ /  )" << std::endl;
    std::cout << R"(/_/ /_/ /_/\___/_/ /_/\__,_/ )" << std::endl;
    std::cout << "Persons in queue: " << queueSize_ << "\n" << std::endl;
    std::cout << "1. Add person to queue" << std::endl;
    std::cout << "2. Offer person housing" << std::endl;
    std::cout << "3. Print whole queue" << std::endl;
    std::cout << "4. Print person" << std::endl;
    std::cout << "5. Remove person from queue" << std::endl;
    std::cout << "6. Save queue to file" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << std::string(20, '=') << std::endl;

    int choice = getIntFromInput("Choose an option (1-7): ", false, true, 1, 7);
    clearScreen();

    switch (choice) {
    case 1:
      addToQueue();
      break;
    case 2:
      offerHousing();
      break;
    case 3:
      printQueue();
      break;
    case 4:
      printPerson();
      break;
    case 5:
      removeFromQueue();
      break;
    case 6:
      saveQueueToFile();
      break;
    case 7:
      return 0;
    default:
      break;
    }

    pauseProgram();
    clearScreen();
  }
}

void HousingQ::addToQueue() {
  std::cout << "ADD PERSON\n" << std::endl;

  std::string firstName = getStringFromInput("Enter first name: ");
  std::string lastName = getStringFromInput("Enter last name: ");
  std::string streetAddress = getStringFromInput("Enter street address: ");
  std::string postalCode = getStringFromInput("Enter postal code: ");
  std::string city = getStringFromInput("Enter city: ");
  std::string personNr = getStringFromInput("Enter personal number: ");
  int skoNr = getIntFromInput("Enter shoe size: ");

  qlist_.enque(
      Person(Name(firstName, lastName), Address(streetAddress, postalCode, city), personNr, skoNr));
  ++queueSize_;
}

void HousingQ::offerHousing() {
  if (qlist_.isEmpty()) {
    std::cout << "The queue is empty." << std::endl;
    return;
  }

  Person tmpPerson;
  if (qlist_.deque(tmpPerson)) {
    std::cout << "The following person has been offered housing and has been removed from the queue:\n"
              << std::endl;
    showPersonHeader();
    Person::showPerson(tmpPerson);
    --queueSize_;
  }
}

void HousingQ::printQueue() {
  if (qlist_.isEmpty()) {
    std::cout << "The queue is empty." << std::endl;
    return;
  }

  std::cout << "Number of people in queue: " << queueSize_ << "\n" << std::endl;

  std::cout << std::left << std::setw(5) << "Pos. ";
  showPersonHeader();

  int position = 1;
  for (QIterator qit = qlist_.begin(); qit != qlist_.end(); ++qit) {
    std::cout << std::left << std::setw(5) << position;
    Person::showPerson(*qit);
    ++position;
  }
}

void HousingQ::printPerson() {
  if (qlist_.isEmpty()) {
    std::cout << "The queue is empty." << std::endl;
    return;
  }

  std::cout << "PRINT PERSON\n" << std::endl;
  std::string searchString = getStringFromInput("Enter personal number to search for: ");

  int position = 1;
  bool found = false;

  for (QIterator qit = qlist_.begin(); qit != qlist_.end(); ++qit) {
    if ((*qit).getPersnr() == searchString) {
      std::cout << std::left << std::setw(5) << "\nPos. ";
      showPersonHeader();
      std::cout << std::left << std::setw(5) << position;
      Person::showPerson(*qit);
      found = true;
    }
    ++position;
  }

  if (!found) {
    std::cout << "Person with personal number " << searchString << " was not found." << std::endl;
  }
}

void HousingQ::removeFromQueue() {
  if (qlist_.isEmpty()) {
    std::cout << "The queue is empty." << std::endl;
    return;
  }

  std::cout << "REMOVE PERSON FROM QUEUE\n" << std::endl;

  std::string searchString =
      getStringFromInput("Enter personal number of person to remove from queue: ");
  bool found = false;
  QIterator qit;
  Item item;
  for (qit = qlist_.begin(); qit != qlist_.end(); ++qit) {
    if ((*qit).getPersnr() == searchString) {
      found = true;
      item = *qit;
      break;
    }
  }

  if (found) {
    if (qlist_.del(*qit)) {
      std::cout << "Successfully removed "
                << item.getName().getFirstName() + " " + item.getName().getLastName() << " ("
                << item.getPersnr() << ") from queue." << std::endl;
      --queueSize_;
    } else {
      std::cout << "Could not remove "
                << item.getName().getFirstName() + " " + item.getName().getLastName() << " ("
                << item.getPersnr() << ") from queue." << std::endl;
    }
  } else {
    std::cout << "Personal number not found." << std::endl;
  }
}

void HousingQ::readQueueFromFile() {
  std::ifstream inFile(filename_);

  if (inFile.is_open()) {
    Person tmpPerson;

    while (inFile >> tmpPerson) {
      qlist_.enque(tmpPerson);
      ++queueSize_;
    }
    inFile.close();
  } else {
    std::cout << "Couldn't open " << filename_ << ", but that (probably) just means it didn't exist! That's OK." << std::endl;
  }
}

void HousingQ::saveQueueToFile() {
  std::ofstream outFile(filename_);

  if (outFile.is_open()) {
    for (QIterator qit = qlist_.begin(); qit != qlist_.end(); ++qit) {
      outFile << *qit;
    }
    outFile.close();
    std::cout << "Queue saved to " << filename_ << "." << std::endl;
  } else {
    std::cout << "Could not open " << filename_ << " for writing." << std::endl;
  }
}
