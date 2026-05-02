#pragma once

#include "MArc.h"
#include "MObject.h"

class OArc : public MArc, public MObject {
private:
  std::string printPhrase;

public:
  OArc(Point base = {}, Point centerLocal = {}, float radius = 0.0f, float startDeg = 0.0f,
       float endDeg = 0.0f, Color color = {}, const std::string& phrase = "");
  ~OArc();

  std::string oprint() const;
};
