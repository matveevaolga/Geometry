#include "../vector.h"
#include "../ray.h"
#include "../line.h"
#include "../segment.h"

namespace geometry {
Ray::Ray(Point start, Point end) : ray_start_point_(start), ray_end_point_(end) {
}
Ray::Ray() = default;
Ray& Ray::Move(const Vector& delta_vector) {
  this->ray_start_point_.Move(delta_vector);
  ray_end_point_.Move(delta_vector);
  return *this;
}
Point Ray::GetRayStartPoint() const {
  return ray_start_point_;
}
Point Ray::GetRayEndPoint() const {
  return ray_end_point_;
}
bool Ray::ContainsPoint(const Point& point) const {
  Line line_with_ray = Line(ray_start_point_, ray_end_point_);
  if (!line_with_ray.ContainsPoint(point)) {
    return false;
  }
  return (point - ray_start_point_).GetScalarProduct(ray_end_point_ - ray_start_point_) >= 0;
}
bool Ray::CrossesSegment(const Segment& right) const {
  if (right.ContainsPoint(ray_start_point_)) {
    return true;
  }
  Line this_as_line = Line(ray_start_point_, ray_end_point_);
  Line right_as_line = Line(right.GetSegmentStartPoint(), right.GetSegmentEndPoint());
  if (this_as_line.Parralel(right_as_line)) {
    return ContainsPoint(right.GetSegmentStartPoint()) || ContainsPoint(right.GetSegmentEndPoint());
  }
  Vector right_as_vector = right.GetSegmentEndPoint() - right.GetSegmentStartPoint();
  Vector this_as_vector = ray_end_point_ - ray_start_point_;
  Vector this_to_right = ray_start_point_ - right.GetSegmentStartPoint();
  return GetKosProduct(this_to_right, right_as_vector) * GetKosProduct(this_as_vector, right_as_vector) <= 0;
}
Ray* Ray::Clone() const {
  return new Ray(ray_start_point_, ray_end_point_);
}
std::string Ray::ToString() const {
  return "Ray(" + ray_start_point_.ToString() + ", " + (ray_end_point_ - ray_start_point_).ToString() + ")";
}
}  // namespace geometry