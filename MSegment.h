#pragma once

#include "Figure.h"
#include "MLine.h"
#include "MArc.h"
#include "MObject.h"

class MSegment : public virtual Figure, public MLine, public MArc, public virtual MOSegment {
public:
  MSegment(Point base = {}, Point lineStartLocal = {}, Point lineEndLocal = {}, Point centerLocal = {},
           float radius = 0.0f, float startDeg = 0.0f, float endDeg = 0.0f, Color color = {});
  ~MSegment();

  void draw() const override;
};
