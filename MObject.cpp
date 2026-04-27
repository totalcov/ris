#include "MObject.h"

#include <iostream>

void MObject::printObjectText() {
  std::wcout << L"я объект" << std::endl;
}

void MOLine::printLineObjectText() const {
  std::wcout << L"я объект линии" << std::endl;
}

void MOArc::printArcObjectText() const {
  std::wcout << L"я объект дуги" << std::endl;
}

void MOSector::printSectorHierarchy() const {
  std::wcout << L"я сектор" << std::endl;
  std::wcout << L"я линия сектора" << std::endl;
  printLineObjectText();
  std::wcout << L"я линия сектора" << std::endl;
  printLineObjectText();
  std::wcout << L"я дуга сектора" << std::endl;
  printArcObjectText();
}

void MOSegment::printSegmentHierarchy() const {
  std::wcout << L"я сегмент" << std::endl;
  std::wcout << L"я линия сегмента" << std::endl;
  printLineObjectText();
  std::wcout << L"я дуга сегмента" << std::endl;
  printArcObjectText();
}

MNumber::MNumber() {
  printObjectText();
  std::wcout << L"я число 5" << std::endl;
}
