#pragma once
#include "ishape.h"
#include "point.h"

namespace geometry {
class Circle : public IShape {
  Point center_;
  int64_t radius_;

 public:
  Circle(Point, int64_t);
  Circle();
  Circle& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  Circle* Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry