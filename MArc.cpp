#include "MArc.h"

#include "graphlib.h"

MArc::MArc() = default;

MArc::MArc(Point center, float radius, float startDeg, float endDeg, Color color)
    : Figure(center, color), radius_(radius), startDeg_(startDeg), endDeg_(endDeg) {}

MArc::~MArc() = default;

void MArc::draw() const {
  draw_arc(base_.x, base_.y, radius_, startDeg_, endDeg_, color_.r, color_.g, color_.b);
}

float MArc::radius() const { return radius_; }
void MArc::setRadius(float r) { radius_ = r; }

float MArc::startDeg() const { return startDeg_; }
void MArc::setStartDeg(float deg) { startDeg_ = deg; }

float MArc::endDeg() const { return endDeg_; }
void MArc::setEndDeg(float deg) { endDeg_ = deg; }

