#include "OLine.h"

#include <iostream>

OLine::OLine(Point base, Point startLocal, Point endLocal, Color color, const std::string& phrase)
    : Figure(base, color), MLine(base, startLocal, endLocal, color), MObject(), printPhrase(phrase) {}

OLine::~OLine() {}

std::string OLine::oprint() const
{
    return "I am Line" + printPhrase;
}