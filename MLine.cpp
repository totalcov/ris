#include "MLine.h"

#include "graphlib.h"

MLine::MLine(Point base, Point startLocal, Point endLocal, Color color)
    : Figure(base, color), startLocal_(startLocal), endLocal_(endLocal) {
  draw();
}

MLine::~MLine() {}

void MLine::draw() const {
  const Point start{base_.x + startLocal_.x, base_.y + startLocal_.y};
  const Point end{base_.x + endLocal_.x, base_.y + endLocal_.y};
  draw_line(start.x, start.y, end.x, end.y, color_.r, color_.g, color_.b);
}

Point MLine::startLocal() const { return startLocal_; }

void MLine::setStart(Point p) { startLocal_ = p; }

Point MLine::endLocal() const { return endLocal_; }

void MLine::setEnd(Point p) { endLocal_ = p; }
