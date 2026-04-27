#include "MSector.h"

MSector::MSector(Point base, Point firstLineStartLocal, Point firstLineEndLocal, Point secondLineStartLocal,
                 Point secondLineEndLocal, Point centerLocal, float radius, float startDeg, float endDeg,
                 Color color)
    : Figure(base, color),
      MLine(base, firstLineStartLocal, firstLineEndLocal, color, false),
      MArc(base, centerLocal, radius, startDeg, endDeg, color, false),
      secondLineStartLocal_(secondLineStartLocal),
      secondLineEndLocal_(secondLineEndLocal) {
  MObject::printObjectText();
  printSectorHierarchy();
  draw();
}

MSector::~MSector() {}

void MSector::draw() const {
  MLine::draw();
  MLine secondLine(base_, secondLineStartLocal_, secondLineEndLocal_, color_, false);
  secondLine.draw();
  MArc::draw();
}
