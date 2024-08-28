#pragma once
#include "ishape.h"
#include "point.h"
#include "line.h"

namespace geometry {
class Segment : public IShape {
  Point segment_start_point_;
  Point segment_end_point_;

 public:
  Segment(Point, Point);
  Segment();
  Point GetSegmentStartPoint() const;
  Point GetSegmentEndPoint() const;
  Segment& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  Segment* Clone() const override;
  std::string ToString() const override;
  friend bool Line::CrossesSegment(const Segment& right) const;
};
}  // namespace geometry