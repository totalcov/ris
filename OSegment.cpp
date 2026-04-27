#include "OSegment.h"

#include <cmath>
#include <iostream>

#include "graphlib.h"

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
            color),
      OArc(base, centerLocal, radius, startDeg, endDeg, color) {}

OSegment::~OSegment() {}

void OSegment::draw() const {
  const Point centerLocal = OArc::centerLocal();
  const Point startLocal = OLine::startLocal();
  const Point endLocal = OLine::endLocal();

  const Point center{base_.x + centerLocal.x, base_.y + centerLocal.y};
  const Point start{base_.x + startLocal.x, base_.y + startLocal.y};
  const Point end{base_.x + endLocal.x, base_.y + endLocal.y};

  draw_arc(center.x, center.y, OArc::radius(), OArc::startDeg(), OArc::endDeg(), color_.r,
           color_.g, color_.b);
  draw_line(start.x, start.y, end.x, end.y, color_.r, color_.g, color_.b);
}

void OSegment::print() const {
  std::wcout << L"я сегмент\n";
  OLine::printPart(L"сегмента");
  OArc::printPart(L"сегмента");
}

void OSegment::setCenter(Point p) {
  OArc::setCenter(p);
  syncChord();
}

void OSegment::setRadius(float r) {
  OArc::setRadius(r);
  syncChord();
}

void OSegment::setStartDeg(float deg) {
  OArc::setStartDeg(deg);
  syncChord();
}

void OSegment::setEndDeg(float deg) {
  OArc::setEndDeg(deg);
  syncChord();
}

void OSegment::syncChord() {
  OLine::setStart(pointOnArc(OArc::centerLocal(), OArc::radius(), OArc::startDeg()));
  OLine::setEnd(pointOnArc(OArc::centerLocal(), OArc::radius(), OArc::endDeg()));
}
