#pragma once

#include "MLine.h"
#include "MObject.h"

class OLine : public MLine, public MObject {
private:
    std::string printPhrase;


  public:
  OLine(Point base = {}, Point startLocal = {}, Point endLocal = {}, Color color = {}, const std::string& phrase = "");
  ~OLine();

  std::string oprint() const;
};
