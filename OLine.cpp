#include "OLine.h"

#include <iostream>

OLine::OLine(Point base, Point startLocal, Point endLocal, Color color)
    : Figure(base, color), MLine(base, startLocal, endLocal, color) {}

OLine::~OLine() {}

void OLine::print() const {
  std::wcout << L"я линия\n";
}

void OLine::printPart(const wchar_t* ownerName) const {
  std::wcout << L"\tя линия " << ownerName << L"\n";
}
