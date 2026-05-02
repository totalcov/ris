#pragma once

#include "MArc.h"
#include "MLine.h"

class MSegment : public MLine, public MArc, virtual public Figure {
public:
  MSegment();
  MSegment(Point base, Point centerLocal, float radius, float startDeg, float endDeg, Color color);
  ~MSegment() override;

  void draw() const override;

  static Point pointOnArc(Point centerLocal, float radius, float deg);
};
