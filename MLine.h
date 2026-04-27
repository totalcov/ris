#pragma once

#include "Figure.h"
#include "MObject.h"

class MLine : public virtual Figure, public virtual MOLine {
public:
  MLine(Point base = {}, Point startLocal = {}, Point endLocal = {}, Color color = {}, bool autoInit = true);
  ~MLine();

  void draw() const override;

  Point startLocal() const;
  void setStart(Point p);

  Point endLocal() const;
  void setEnd(Point p);

private:
  Point startLocal_{};
  Point endLocal_{};
};
