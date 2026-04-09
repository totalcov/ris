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
  Figure();
  Figure(Point base, Color color);
  virtual ~Figure();

  Figure(const Figure&) = default;
  Figure& operator=(const Figure&) = default;
  Figure(Figure&&) = default;
  Figure& operator=(Figure&&) = default;

  virtual void draw() const = 0;

  Point base() const;
  void setBase(Point p);

  Color color() const;
  void setColor(Color c);

protected:
  Point base_{};
  Color color_{};
};

