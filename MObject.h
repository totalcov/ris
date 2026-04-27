#pragma once

class MObject {
public:
  virtual ~MObject();
  virtual void print() const;
};

class MNumber : public MObject {
public:
  virtual ~MNumber();
  virtual void print() const;
};
