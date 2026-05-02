#pragma once

#include "MArc.h"
#include "MLine.h"

class MFirstSectorLine : public MLine {
public:
  MFirstSectorLine(Point base = {}, Point startLocal = {}, Point endLocal = {}, Color color = {})
      : Figure(base, color), MLine(base, startLocal, endLocal, color) {}
};

class MSectorLine : public MLine {
public:
  MSectorLine(Point base = {}, Point startLocal = {}, Point endLocal = {}, Color color = {})
      : Figure(base, color), MLine(base, startLocal, endLocal, color) {}
};

class MSector : public MFirstSectorLine, public MSectorLine, public MArc, virtual public Figure {
public:
  MSector();
  MSector(Point base, Point centerLocal, float radius, float startDeg, float endDeg, Color color);
  ~MSector() override;

  void draw() const override;

  Point firstStartLocal() const;
  Point firstEndLocal() const;
  Point secondStartLocal() const;
  Point secondEndLocal() const;

  static Point pointOnArc(Point centerLocal, float radius, float deg);
};
