#include "Figure.h"

Figure::Figure(Point base, Color color) : base_(base), color_(color) {}

Figure::~Figure() = default;

void Figure::erase() {
  const Color oldColor = color_;
  color_ = {0.0f, 0.0f, 0.0f};
  draw();
  color_ = oldColor;
}

void Figure::move(float dx, float dy) {
  erase();
  base_.x += dx;
  base_.y += dy;
  draw();
}

Color Figure::color() const { return color_; }
void Figure::setColor(Color c) {
    color_ = c;
    move(0,0); 
    }
