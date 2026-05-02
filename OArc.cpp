#include "OArc.h"

#include <iostream>

OArc::OArc(Point base, Point centerLocal, float radius, float startDeg, float endDeg, Color color,
           const std::string& phrase)
    : Figure(base, color), MArc(base, centerLocal, radius, startDeg, endDeg, color), MObject(), printPhrase(phrase) {}

OArc::~OArc() {}

std::string OArc::oprint() const
{
    return "I am Arc" + printPhrase;
}
