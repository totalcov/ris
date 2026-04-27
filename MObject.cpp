#include "MObject.h"

#include <iostream>

MObject::~MObject() {}

void MObject::print() const {
  std::wcout << L"я объект\n";
}

MNumber::~MNumber() {}

void MNumber::print() const {
  std::wcout << L"я число 5\n";
}
