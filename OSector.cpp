#include "OSector.h"

#include <cmath>
#include <iostream>

#include "graphlib.h"

namespace {
const float kPi = 3.14159265358979323846f;

Point pointOnArc(Point centerLocal, float radius, float deg) {
  const float angle = deg * kPi / 180.0f;
  return {centerLocal.x + radius * std::cos(angle), centerLocal.y + radius * std::sin(angle)};
}

void eraseChord(Point base, Point startLocal, Point endLocal) {
  const Point start{base.x + startLocal.x, base.y + startLocal.y};
  const Point end{base.x + endLocal.x, base.y + endLocal.y};
  draw_line(start.x, start.y, end.x, end.y, 0.0f, 0.0f, 0.0f);
}
}  // namespace

OSector::OSector(Point base, Point centerLocal, float radius, float startDeg, float endDeg,
                 Color color)
    : Figure(base, color),
      OLine(base, pointOnArc(centerLocal, radius, startDeg), pointOnArc(centerLocal, radius, endDeg),
            color),
      OArc(base, centerLocal, radius, startDeg, endDeg, color) {
  eraseChord(base_, OLine::startLocal(), OLine::endLocal());
  draw();
}

OSector::~OSector() {}

void OSector::draw() const {
  const Point centerLocal = OArc::centerLocal();
  const Point startLocal = OLine::startLocal();
  const Point endLocal = OLine::endLocal();

  const Point center{base_.x + centerLocal.x, base_.y + centerLocal.y};
  const Point start{base_.x + startLocal.x, base_.y + startLocal.y};
  const Point end{base_.x + endLocal.x, base_.y + endLocal.y};

  draw_arc(center.x, center.y, OArc::radius(), OArc::startDeg(), OArc::endDeg(), color_.r,
           color_.g, color_.b);
  draw_line(center.x, center.y, start.x, start.y, color_.r, color_.g, color_.b);
  draw_line(center.x, center.y, end.x, end.y, color_.r, color_.g, color_.b);
}

void OSector::print() const {
  std::wcout << L"я сектор\n";
  OLine::printPart(L"сектора");
  OLine::printPart(L"сектора");
  OArc::printPart(L"сектора");
}

void OSector::setCenter(Point p) {
  OArc::setCenter(p);
  syncRays();
}

void OSector::setRadius(float r) {
  OArc::setRadius(r);
  syncRays();
}

void OSector::setStartDeg(float deg) {
  OArc::setStartDeg(deg);
  syncRays();
}

void OSector::setEndDeg(float deg) {
  OArc::setEndDeg(deg);
  syncRays();
}

void OSector::syncRays() {
  OLine::setStart(pointOnArc(OArc::centerLocal(), OArc::radius(), OArc::startDeg()));
  OLine::setEnd(pointOnArc(OArc::centerLocal(), OArc::radius(), OArc::endDeg()));
}
