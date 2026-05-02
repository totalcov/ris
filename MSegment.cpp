#include "MSegment.h"

#include <cmath>

namespace {

constexpr float kPi = 3.1415926535f;

float degToRad(float deg) {
  return deg * (kPi / 180.0f);
}

}  // namespace

MSegment::MSegment() : Figure(), MLine(), MArc() {
  draw();
}

MSegment::MSegment(Point base, Point centerLocal, float radius, float startDeg, float endDeg, Color color)
    : Figure(base, color),
      MLine(base, pointOnArc(centerLocal, radius, startDeg), pointOnArc(centerLocal, radius, endDeg), color),
      MArc(base, centerLocal, radius, startDeg, endDeg, color) {
  draw();
}

MSegment::~MSegment() {}

void MSegment::draw() const {
  MArc::draw();
  MLine::draw();
}

Point MSegment::pointOnArc(Point centerLocal, float radius, float deg) {
  const float rad = degToRad(deg);
  return {centerLocal.x + radius * std::cos(rad), centerLocal.y + radius * std::sin(rad)};
}
