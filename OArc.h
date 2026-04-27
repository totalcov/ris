#pragma once

#include "MArc.h"
#include "MObject.h"

class OArc : public MArc, public MObject {
public:
  OArc(Point base = {}, Point centerLocal = {}, float radius = 0.0f, float startDeg = 0.0f,
       float endDeg = 0.0f, Color color = {});
  virtual ~OArc();

  virtual void print() const;
  void printPart(const wchar_t* ownerName) const;
};
