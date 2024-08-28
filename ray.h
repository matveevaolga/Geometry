#pragma once
#include "ishape.h"
#include "point.h"

namespace geometry {
class Ray : public IShape {
  Point ray_start_point_;
  Point ray_end_point_;

 public:
  Ray(Point, Point);
  Ray();
  Point GetRayStartPoint() const;
  Point GetRayEndPoint() const;
  Ray& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  Ray* Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry