#include "../polygon.h"
#include "../point.h"
#include "../vector.h"
#include "../ray.h"
#include "../segment.h"
#include <cmath>
#include <climits>

namespace geometry {
Polygon::Polygon(std::vector<Point> pts) : points_(pts) {
}
Polygon::Polygon() = default;
Polygon& Polygon::Move(const Vector& delta_vector) {
  for (size_t i = 0; i < points_.size(); ++i) {
    points_[i].Move(delta_vector);
  }
  return *this;
}
bool Polygon::ContainsPoint(const Point& point) const {
  Segment reference_segment(point, Point(llabs(GetMaxXCoord()) + 1, point.GetPointY() + 1));
  int64_t count = 0;
  for (size_t i = 0; i < points_.size(); ++i) {
    size_t pair = (i + 1) % points_.size();
    Segment segment(points_[i], points_[pair]);
    if (segment.ContainsPoint(point)) {
      return true;
    }
    if (reference_segment.CrossesSegment(segment)) {
      count++;
    }
  }
  return count % 2 != 0;
}
bool Polygon::CrossesSegment(const Segment& right) const {
  for (size_t i = 0; i < points_.size(); ++i) {
    size_t pair = (i + 1) % points_.size();
    Segment segment(points_[i], points_[pair]);
    if (segment.CrossesSegment(right)) {
      return true;
    }
  }
  return false;
}
Polygon* Polygon::Clone() const {
  return new Polygon(points_);
}
std::string Polygon::ToString() const {
  std::string result = "Polygon(";
  for (Point point : points_) {
    result += point.ToString() + ", ";
  }
  if (!points_.empty()) {
    result = result.substr(0, result.length() - 2);
  }
  result += ")";
  return result;
}
int64_t Polygon::GetMaxXCoord() const {
  if (points_.empty()) {
    return 0;
  }
  int64_t result = LONG_MIN;
  for (Point point : points_) {
    result = std::max(point.GetPointX(), result);
  }
  return result;
}
}  // namespace geometry