#pragma once

struct Point {
  float x{};
  float y{};
};

struct Color {
  float r{};
  float g{};
  float b{};
};

class Figure {
public:
  Figure(Point base = {}, Color color = {});
  virtual ~Figure();

  virtual void draw() const = 0;

  void move(float dx, float dy);
  void erase();

  Point base() const;
  void setBase(Point p);

  Color color() const;
  void setColor(Color c);

protected:
  Point base_{};
  Color color_{};
};
