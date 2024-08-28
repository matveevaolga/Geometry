#pragma once
#include "ishape.h"
#include "point.h"
#include <vector>

namespace geometry {
class Polygon : public IShape {
  std::vector<Point> points_;
  int64_t GetMaxXCoord() const;

 public:
  explicit Polygon(std::vector<Point>);
  Polygon();
  Polygon& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  Polygon* Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry