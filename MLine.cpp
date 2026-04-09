#include "MLine.h"

#include "graphlib.h"

MLine::MLine() = default;

MLine::MLine(Point a, Point b, Color color) : Figure(a, color), end_(b) {}

MLine::~MLine() = default;

void MLine::draw() const {
  draw_line(base_.x, base_.y, end_.x, end_.y, color_.r, color_.g, color_.b);
}

Point MLine::end() const { return end_; }

void MLine::setEnd(Point p) { end_ = p; }

