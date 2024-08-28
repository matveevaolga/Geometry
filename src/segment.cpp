#include "../vector.h"
#include "../segment.h"
#include "../line.h"

namespace geometry {
Segment::Segment(Point start, Point end) : segment_start_point_(start), segment_end_point_(end) {
}
Segment::Segment() = default;
Segment& Segment::Move(const Vector& delta_vector) {
  segment_start_point_.Move(delta_vector);
  segment_end_point_.Move(delta_vector);
  return *this;
}
Point Segment::GetSegmentStartPoint() const {
  return segment_start_point_;
}
Point Segment::GetSegmentEndPoint() const {
  return segment_end_point_;
}
bool Segment::ContainsPoint(const Point& point) const {
  Line this_as_line = Line(segment_start_point_, segment_end_point_);
  if (!this_as_line.ContainsPoint(point)) {
    return false;
  }
  Vector start_to_point = Vector(segment_start_point_, point);
  Vector end_to_point = Vector(segment_end_point_, point);
  return start_to_point.GetScalarProduct(end_to_point) <= 0;
}
bool Segment::CrossesSegment(const Segment& right) const {
  if (right.ContainsPoint(segment_start_point_) || right.ContainsPoint(segment_end_point_) ||
      ContainsPoint(right.segment_start_point_) || ContainsPoint(right.segment_end_point_)) {
    return true;
  }
  Line this_as_line = Line(segment_start_point_, segment_end_point_);
  Line right_as_line = Line(right.segment_start_point_, right.segment_end_point_);
  return !this_as_line.Parralel(right_as_line) && this_as_line.CrossesSegment(right) &&
         right_as_line.CrossesSegment(*this);
}
Segment* Segment::Clone() const {
  return new Segment(segment_start_point_, segment_end_point_);
}
std::string Segment::ToString() const {
  return "Segment(" + segment_start_point_.ToString() + ", " + segment_end_point_.ToString() + ")";
}
}  // namespace geometry