#include "MSector.h"

#include <cmath>

namespace {

constexpr float kPi = 3.1415926535f;

float degToRad(float deg) {
  return deg * (kPi / 180.0f);
}

}  // namespace

MSector::MSector() : Figure(), MFirstSectorLine(), MSectorLine(), MArc() {
  draw();
}

MSector::MSector(Point base, Point centerLocal, float radius, float startDeg, float endDeg, Color color)
    : Figure(base, color),
      MFirstSectorLine(base, centerLocal, pointOnArc(centerLocal, radius, startDeg), color),
      MSectorLine(base, centerLocal, pointOnArc(centerLocal, radius, endDeg), color),
      MArc(base, centerLocal, radius, startDeg, endDeg, color) {
  draw();
}

MSector::~MSector() {}

void MSector::draw() const {
  MArc::draw();
  MFirstSectorLine::draw();
  MSectorLine::draw();
}

Point MSector::firstStartLocal() const { return MFirstSectorLine::startLocal(); }

Point MSector::firstEndLocal() const { return MFirstSectorLine::endLocal(); }

Point MSector::secondStartLocal() const { return MSectorLine::startLocal(); }

Point MSector::secondEndLocal() const { return MSectorLine::endLocal(); }

Point MSector::pointOnArc(Point centerLocal, float radius, float deg) {
  const float rad = degToRad(deg);
  return {centerLocal.x + radius * std::cos(rad), centerLocal.y + radius * std::sin(rad)};
}
