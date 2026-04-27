#pragma once

class MObject {
public:
  static void printObjectText();
};

class MOLine {
protected:
  void printLineObjectText() const;
};

class MOArc {
protected:
  void printArcObjectText() const;
};

class MOSector : public virtual MOLine, public virtual MOArc {
protected:
  void printSectorHierarchy() const;
};

class MOSegment : public virtual MOLine, public virtual MOArc {
protected:
  void printSegmentHierarchy() const;
};

class MNumber : public MObject {
public:
  MNumber();
};
