#pragma once

#include "Figure.h"

class MLine final : public Figure {
public:
  MLine();
  MLine(Point a, Point b, Color color);
  ~MLine() override;

  void draw() const override;

  Point end() const;
  void setEnd(Point p);

private:
  Point end_{};
};

