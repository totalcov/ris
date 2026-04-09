#pragma once

#include "Figure.h"

class MArc final : public Figure {
public:
  MArc();
  MArc(Point center, float radius, float startDeg, float endDeg, Color color);
  ~MArc() override;

  void draw() const override;

  float radius() const;
  void setRadius(float r);

  float startDeg() const;
  void setStartDeg(float deg);

  float endDeg() const;
  void setEndDeg(float deg);

private:
  float radius_{};
  float startDeg_{};
  float endDeg_{};
};

