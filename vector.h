#pragma once
#include "ishape.h"

namespace geometry {
class Vector {
  int64_t vector_x_;
  int64_t vector_y_;

 public:
  Vector(Point, Point);
  Vector(int64_t, int64_t);
  Vector();
  int64_t GetVectorX() const;
  int64_t GetVectorY() const;
  double GetLength() const;
  Vector operator+() const;
  Vector operator-() const;
  Vector operator+(const Vector) const;
  Vector operator-(const Vector) const;
  Vector operator*(int64_t) const;
  Vector operator/(int64_t) const;
  Vector& operator+=(const Vector&);
  Vector& operator-=(const Vector&);
  Vector& operator*=(int64_t);
  Vector& operator/=(int64_t);
  friend bool operator==(const Vector&, const Vector&);
  std::string ToString() const;
  int64_t GetScalarProduct(const Vector) const;
  friend int64_t GetKosProduct(const Vector, const Vector);
};
}  // namespace geometry