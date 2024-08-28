#include "../circle.h"
#include "../point.h"
#include "../vector.h"
#include "../segment.h"
#include <cmath>

namespace geometry {
Circle::Circle(Point cent, int64_t rad) : center_(cent), radius_(rad) {
}
Circle::Circle() = default;
Circle& Circle::Move(const Vector& delta_vector) {
  center_.Move(delta_vector);
  return *this;
}
bool Circle::ContainsPoint(const Point& point) const {
  return (point - center_).GetLength() <= static_cast<double>(radius_);
}
bool Circle::CrossesSegment(const Segment& right) const {
  if (right.ContainsPoint(center_)) {
    return true;
  }
  double len1 = (center_ - right.GetSegmentStartPoint()).GetLength();
  double len2 = (center_ - right.GetSegmentEndPoint()).GetLength();
  Line seg_as_line(right.GetSegmentStartPoint(), right.GetSegmentEndPoint());
  int64_t num = llabs(seg_as_line.CountFromPoint(center_));
  int64_t den = seg_as_line.GetYCoef() * seg_as_line.GetYCoef() + seg_as_line.GetXCoef() * seg_as_line.GetYCoef();
  double distance = den == 0 ? std::min(len1, len2) : static_cast<double>(num) / sqrt(den);
  if (distance > static_cast<double>(radius_) && (distance <= std::min(len1, len2))) {
    return false;
  }
  return len1 >= static_cast<double>(radius_) || len2 >= static_cast<double>(radius_);
}
Circle* Circle::Clone() const {
  return new Circle(center_, radius_);
}
std::string Circle::ToString() const {
  return "Circle(" + center_.ToString() + ", " + std::to_string(radius_) + ")";
}
}  // namespace geometry