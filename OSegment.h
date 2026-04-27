#pragma once

#include "Figure.h"
#include "OArc.h"
#include "OLine.h"

class OSegment : public virtual Figure, public OLine, public OArc {
public:
  OSegment(Point base = {}, Point centerLocal = {}, float radius = 0.0f, float startDeg = 0.0f,
           float endDeg = 0.0f, Color color = {});
  virtual ~OSegment();

  virtual void draw() const;
  virtual void print() const;

  void setCenter(Point p);
  void setRadius(float r);
  void setStartDeg(float deg);
  void setEndDeg(float deg);

private:
  void syncChord();
};
