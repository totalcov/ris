#pragma once

#include "Figure.h"
#include "MArc.h"
#include "MLine.h"

class MSector : public virtual Figure, public MLine, public MArc {
public:
  MSector(Point base = {}, Point centerLocal = {}, float radius = 0.0f, float startDeg = 0.0f,
          float endDeg = 0.0f, Color color = {});
  virtual ~MSector();

  virtual void draw() const;

  void setCenter(Point p);
  void setRadius(float r);
  void setStartDeg(float deg);
  void setEndDeg(float deg);

private:
  void syncRays(); // функция нужна для синхронизации лучей с дугой, чтобы они всегда были на границах сектора
};
