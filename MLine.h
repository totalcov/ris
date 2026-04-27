#pragma once

#include "Figure.h"

class MLine : public virtual Figure {
public:
  MLine(Point base = {}, Point startLocal = {}, Point endLocal = {}, Color color = {});
  virtual ~MLine();

  virtual void draw() const;

  Point startLocal() const;
  void setStart(Point p);

  Point endLocal() const;
  void setEnd(Point p);

private:
  Point startLocal_{};
  Point endLocal_{};
};
