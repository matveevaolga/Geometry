#pragma once
#include "ishape.h"

namespace geometry {
class Point : public IShape {
  int64_t point_x_;
  int64_t point_y_;

 public:
  Point(int64_t, int64_t);
  Point();
  int64_t GetPointX() const;
  int64_t GetPointY() const;
  Point& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  Point* Clone() const override;
  std::string ToString() const override;
  Vector operator-(const Point) const;
  friend bool operator==(const Point&, const Point&);
};
}  // namespace geometry