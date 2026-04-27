#include "MArc.h"

#include "graphlib.h"

MArc::MArc(Point base, Point centerLocal, float radius, float startDeg, float endDeg, Color color, bool autoInit)
    : Figure(base, color),
      centerLocal_(centerLocal),
      radius_(radius),
      startDeg_(startDeg),
      endDeg_(endDeg) {
  if (autoInit) {
    MObject::printObjectText();
    printArcObjectText();
    draw();
  }
}

MArc::~MArc() {}

void MArc::draw() const {
  const Point center{base_.x + centerLocal_.x, base_.y + centerLocal_.y};
  draw_arc(center.x, center.y, radius_, startDeg_, endDeg_, color_.r, color_.g, color_.b);
}

Point MArc::centerLocal() const { return centerLocal_; }

void MArc::setCenter(Point p) { centerLocal_ = p; }

float MArc::radius() const { return radius_; }

void MArc::setRadius(float r) { radius_ = r; }

float MArc::startDeg() const { return startDeg_; }

void MArc::setStartDeg(float deg) { startDeg_ = deg; }

float MArc::endDeg() const { return endDeg_; }

void MArc::setEndDeg(float deg) { endDeg_ = deg; }
