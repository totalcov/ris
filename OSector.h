#pragma once

#include "Figure.h"
#include "OArc.h"
#include "OLine.h"

class OFirstSectorLine : public OLine
{
public:
    OFirstSectorLine(Point base = {}, Point startLocal = {}, Point endLocal = {}, Color color = {}, const std::string& phrase = "")
        : Figure(base, color), OLine(base, startLocal, endLocal, color, phrase)
    {}
};

class OSectorLine : public OLine
{
public:
    OSectorLine(Point base = {}, Point startLocal = {}, Point endLocal = {}, Color color = {}, const std::string& phrase = "")
        : Figure(base, color), OLine(base, startLocal, endLocal, color, phrase)
    {}
};

class OSector : public virtual Figure, public OFirstSectorLine, public OSectorLine, public OArc {
public:
  OSector(Point base = {}, Point centerLocal = {}, float radius = 0.0f, float startDeg = 0.0f,
          float endDeg = 0.0f, Color color = {});
  ~OSector();

  void draw() const;
  std::string oprint() const;
};
