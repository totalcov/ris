#include "OSegment.h"

#include <cmath>

namespace {
const float kPi = 3.14159265358979323846f;

Point pointOnArc(Point centerLocal, float radius, float deg) {
  const float angle = deg * kPi / 180.0f;
  return {centerLocal.x + radius * std::cos(angle), centerLocal.y + radius * std::sin(angle)};
}
}  // namespace

OSegment::OSegment(Point base, Point centerLocal, float radius, float startDeg, float endDeg,
                   Color color)
    : Figure(base, color),
      OLine(base, pointOnArc(centerLocal, radius, startDeg), pointOnArc(centerLocal, radius, endDeg),
            color, " 1"),
      OArc(base, centerLocal, radius, startDeg, endDeg, color, " 1") {}

OSegment::~OSegment() {}

void OSegment::draw() const {
  OArc::draw();
  OLine::draw();
}

std::string OSegment::oprint() const
{
    return "I am Segment\n"
        + OLine::oprint() + "\n"
        + OArc::oprint();
}
