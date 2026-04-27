#pragma once

#include "Figure.h"
#include "MArc.h"
#include "MLine.h"

class MSegment : public virtual Figure, public MLine, public MArc {
public:
  MSegment(Point base = {}, Point centerLocal = {}, float radius = 0.0f, float startDeg = 0.0f,
           float endDeg = 0.0f, Color color = {});
  virtual ~MSegment();

  virtual void draw() const;

  void setCenter(Point p);
  void setRadius(float r);
  void setStartDeg(float deg);
  void setEndDeg(float deg);

private:
  void syncChord(); // функция нужна для синхронизации хорды с дугой, чтобы она всегда была на границах сектора
  
};
