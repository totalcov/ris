#include "OSector.h"

#include <cmath>

namespace {
const float kPi = 3.14159265358979323846f;

Point pointOnArc(Point centerLocal, float radius, float deg) {
  const float angle = deg * kPi / 180.0f;
  return {centerLocal.x + radius * std::cos(angle), centerLocal.y + radius * std::sin(angle)};
}
}  // namespace

OSector::OSector(Point base, Point centerLocal, float radius, float startDeg, float endDeg,
                 Color color)
    : Figure(base, color),
      OFirstSectorLine(base, centerLocal, pointOnArc(centerLocal, radius, startDeg), color, " 1"),
      OSectorLine(base, centerLocal, pointOnArc(centerLocal, radius, endDeg), color, " 2"),
      OArc(base, centerLocal, radius, startDeg, endDeg, color, " 1") {}

OSector::~OSector() {}

void OSector::draw() const {
  OArc::draw();
  OFirstSectorLine::draw();
  OSectorLine::draw();
}

std::string OSector::oprint() const
{
    return "I am Sector\n"
        + OFirstSectorLine::oprint() + "\n"
        + OSectorLine::oprint() + "\n"
        + OArc::oprint();
}
