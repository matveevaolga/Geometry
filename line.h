#pragma once
#include "ishape.h"
#include "point.h"

namespace geometry {
class Line : public IShape {
  Point line_first_point_;
  Point line_second_point_;

 public:
  Line(Point, Point);
  Line();
  Point GetLineFirstPoint() const;
  Point GetLineSecondPoint() const;
  int64_t GetXCoef() const;
  int64_t GetYCoef() const;
  int64_t GetFreeCoef() const;
  Line& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  Line* Clone() const override;
  std::string ToString() const override;
  bool Parralel(const Line) const;
  int64_t CountFromPoint(const Point) const;
};
}  // namespace geometry