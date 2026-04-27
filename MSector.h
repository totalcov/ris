#pragma once

#include "Figure.h"
#include "MLine.h"
#include "MArc.h"
#include "MObject.h"

class MSector : public virtual Figure, public MLine, public MArc, public virtual MOSector {
public:
  MSector(Point base = {}, Point firstLineStartLocal = {}, Point firstLineEndLocal = {},
          Point secondLineStartLocal = {}, Point secondLineEndLocal = {}, Point centerLocal = {},
          float radius = 0.0f, float startDeg = 0.0f, float endDeg = 0.0f, Color color = {});
  ~MSector();

  void draw() const override;

private:
  Point secondLineStartLocal_{};
  Point secondLineEndLocal_{};
};
