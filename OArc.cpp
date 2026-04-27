#include "OArc.h"

#include <iostream>

OArc::OArc(Point base, Point centerLocal, float radius, float startDeg, float endDeg, Color color)
    : Figure(base, color), MArc(base, centerLocal, radius, startDeg, endDeg, color) {}

OArc::~OArc() {}

void OArc::print() const {
  std::wcout << L"я дуга\n";
}

void OArc::printPart(const wchar_t* ownerName) const {
  std::wcout << L"\tя дуга " << ownerName << L"\n";
}
