#include "MSegment.h"

MSegment::MSegment(Point base, Point lineStartLocal, Point lineEndLocal, Point centerLocal, float radius,
                   float startDeg, float endDeg, Color color)
    : Figure(base, color),
      MLine(base, lineStartLocal, lineEndLocal, color, false),
      MArc(base, centerLocal, radius, startDeg, endDeg, color, false) {
  MObject::printObjectText();
  printSegmentHierarchy();
  draw();
}

MSegment::~MSegment() {}

void MSegment::draw() const {
  MLine::draw();
  MArc::draw();
}
