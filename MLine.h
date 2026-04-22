#pragma once

#include "Figure.h"

class MLine final : public Figure {
public:
  MLine(Point base = {}, Point startLocal = {}, Point endLocal = {}, Color color = {});
  ~MLine();

  void draw() const;

  Point startLocal() const;
  void setStart(Point p);

  Point endLocal() const;
  void setEnd(Point p);

private:
Point startLocal_{};  
Point endLocal_{}; // конечная точка
};

