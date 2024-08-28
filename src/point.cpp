#include "../ishape.h"
#include "../segment.h"
#include "../vector.h"

namespace geometry {
Point::Point(int64_t x, int64_t y) : point_x_(x), point_y_(y) {
}
Point::Point() = default;
int64_t Point::GetPointX() const {
  return point_x_;
}
int64_t Point::GetPointY() const {
  return point_y_;
}
Point& Point::Move(const Vector& delta_vector) {
  point_x_ += delta_vector.GetVectorX();
  point_y_ += delta_vector.GetVectorY();
  return *this;
}
bool operator==(const Point& left, const Point& right) {
  return left.point_x_ == right.point_x_ && left.point_y_ == right.point_y_;
}
bool Point::ContainsPoint(const Point& right) const {
  return *this == right;
}
bool Point::CrossesSegment(const Segment& segment) const {
  return segment.ContainsPoint(*this);
}
Point* Point::Clone() const {
  return new Point(point_x_, point_y_);
}
std::string Point::ToString() const {
  return "Point(" + std::to_string(point_x_) + ", " + std::to_string(point_y_) + ")";
}
Vector Point::operator-(const Point right) const {
  return {point_x_ - right.point_x_, point_y_ - right.point_y_};
}
}  // namespace geometry