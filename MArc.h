#pragma once

#include "Figure.h"

class MArc : public virtual Figure {
public:
  MArc(Point base = {}, Point centerLocal = {}, float radius = 0.0f, float startDeg = 0.0f,
       float endDeg = 0.0f, Color color = {});
  virtual ~MArc();

  virtual void draw() const;

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
