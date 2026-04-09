#include "Figure.h"

Figure::Figure() = default;

Figure::Figure(Point base, Color color) : base_(base), color_(color) {}

Figure::~Figure() = default;

Point Figure::base() const { return base_; }

void Figure::setBase(Point p) { base_ = p; }

Color Figure::color() const { return color_; }

void Figure::setColor(Color c) { color_ = c; }

