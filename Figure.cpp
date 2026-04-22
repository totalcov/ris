#include "Figure.h"

Figure::Figure(Point base, Color color) : base_(base), color_(color) {}

Figure::~Figure() {}

void Figure::erase(){
    const Color oldColor = color_;
    color_ = {0.0f, 0.0f, 0.0f}; // Черный цвет для стирания
    draw();
    color_ = oldColor;
}

void Figure:: move(float dx, float dy){
    erase(); // Стираем фигуру в старой позиции
    base_.x += dx;
    base_.y += dy;
    draw();
}

Point Figure::base() const { return base_; }
void Figure::setBase(Point p) { base_ = p; }

Color Figure::color() const { return color_; }
void Figure::setColor(Color c) { color_ = c; }
