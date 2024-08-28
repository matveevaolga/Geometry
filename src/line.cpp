#include "../vector.h"
#include "../line.h"
#include "../segment.h"

namespace geometry {
Line::Line(Point start, Point end) : line_first_point_(start), line_second_point_(end) {
}
Line::Line() = default;
Line& Line::Move(const Vector& delta_vector) {
  line_first_point_.Move(delta_vector);
  line_second_point_.Move(delta_vector);
  return *this;
}
Point Line::GetLineFirstPoint() const {
  return line_first_point_;
}
Point Line::GetLineSecondPoint() const {
  return line_second_point_;
}
int64_t Line::GetXCoef() const {
  return line_second_point_.GetPointY() - line_first_point_.GetPointY();
}
int64_t Line::GetYCoef() const {
  return line_first_point_.GetPointX() - line_second_point_.GetPointX();
}
int64_t Line::GetFreeCoef() const {
  int64_t x1 = line_first_point_.GetPointX();
  int64_t x2 = line_second_point_.GetPointX();
  int64_t y1 = line_first_point_.GetPointY();
  int64_t y2 = line_second_point_.GetPointY();
  return -x1 * y2 + x1 * y1 + x2 * y1 - x1 * y1;
}
bool Line::ContainsPoint(const Point& point) const {
  return CountFromPoint(point) == 0;
}
bool Line::CrossesSegment(const Segment& right) const {
  return CountFromPoint(right.GetSegmentStartPoint()) * CountFromPoint(right.GetSegmentEndPoint()) <= 0;
}
Line* Line::Clone() const {
  return new Line(line_first_point_, line_second_point_);
}
std::string Line::ToString() const {
  return "Line(" + std::to_string(GetXCoef()) + ", " + std::to_string(GetYCoef()) + ", " +
         std::to_string(GetFreeCoef()) + ")";
}
bool Line::Parralel(const Line right) const {
  return GetXCoef() * right.GetYCoef() - right.GetXCoef() * GetYCoef() == 0;
}
int64_t Line::CountFromPoint(const Point point) const {
  return point.GetPointX() * GetXCoef() + point.GetPointY() * GetYCoef() + GetFreeCoef();
}
}  // namespace geometry