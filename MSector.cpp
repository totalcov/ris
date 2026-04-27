#include "MSector.h"

#include <cmath>

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

MSector::MSector(Point base, Point centerLocal, float radius, float startDeg, float endDeg,
                 Color color)
    : Figure(base, color),
      MLine(base, pointOnArc(centerLocal, radius, startDeg), pointOnArc(centerLocal, radius, endDeg),
            color),
      MArc(base, centerLocal, radius, startDeg, endDeg, color) {
  eraseChord(base_, MLine::startLocal(), MLine::endLocal());
  draw();
}

MSector::~MSector() {}

void MSector::draw() const {
  const Point centerLocal = MArc::centerLocal();
  const Point startLocal = MLine::startLocal();
  const Point endLocal = MLine::endLocal();

  const Point center{base_.x + centerLocal.x, base_.y + centerLocal.y};
  const Point start{base_.x + startLocal.x, base_.y + startLocal.y};
  const Point end{base_.x + endLocal.x, base_.y + endLocal.y};

  draw_arc(center.x, center.y, MArc::radius(), MArc::startDeg(), MArc::endDeg(), color_.r,
           color_.g, color_.b);
  draw_line(center.x, center.y, start.x, start.y, color_.r, color_.g, color_.b);
  draw_line(center.x, center.y, end.x, end.y, color_.r, color_.g, color_.b);
}

void MSector::setCenter(Point p) {
  MArc::setCenter(p);
  syncRays();
}

void MSector::setRadius(float r) {
  MArc::setRadius(r);
  syncRays();
}

void MSector::setStartDeg(float deg) {
  MArc::setStartDeg(deg);
  syncRays();
}

void MSector::setEndDeg(float deg) {
  MArc::setEndDeg(deg);
  syncRays();
}

void MSector::syncRays() {
  MLine::setStart(pointOnArc(MArc::centerLocal(), MArc::radius(), MArc::startDeg()));
  MLine::setEnd(pointOnArc(MArc::centerLocal(), MArc::radius(), MArc::endDeg()));
}
