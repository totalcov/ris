#pragma once

#include "Figure.h"

class MArc : public Figure {
public:
  MArc();
  MArc(Point base, Point centerLocal, float radius, float startDeg, float endDeg, Color color);
  ~MArc();

  void draw() const;

  Point centerLocal() const;
  void setCenter(Point p);

  float radius() const;
  void setRadius(float r);

  float startDeg() const;
  void setStartDeg(float deg);

  float endDeg() const;
  void setEndDeg(float deg);

private:
  Point centerLocal_{};
  float radius_{};
  float startDeg_{};
  float endDeg_{};
};
