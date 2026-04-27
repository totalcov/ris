#pragma once

#include "Figure.h"
#include "MObject.h"

class MArc : public virtual Figure, public virtual MOArc {
public:
  MArc(Point base = {}, Point centerLocal = {}, float radius = 0.0f, float startDeg = 0.0f,
       float endDeg = 0.0f, Color color = {}, bool autoInit = true);
  ~MArc();

  void draw() const override;

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
