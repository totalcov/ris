#pragma once

#include "MLine.h"
#include "MObject.h"

class OLine : public MLine, public MObject {
public:
  OLine(Point base = {}, Point startLocal = {}, Point endLocal = {}, Color color = {});
  virtual ~OLine();

  virtual void print() const;
  void printPart(const wchar_t* ownerName) const;
};
