#include "../vector.h"
#include "../point.h"
#include <cmath>

namespace geometry {
Vector::Vector(int64_t x, int64_t y) : vector_x_(x), vector_y_(y) {
}
Vector::Vector() = default;
Vector::Vector(Point left, Point right)
    : vector_x_(right.GetPointX() - left.GetPointX()), vector_y_(right.GetPointY() - left.GetPointY()) {
}
int64_t Vector::GetVectorX() const {
  return vector_x_;
}
int64_t Vector::GetVectorY() const {
  return vector_y_;
}
double Vector::GetLength() const {
  return sqrt(pow(vector_x_, 2) + pow(vector_y_, 2));
}
Vector Vector::operator+() const {
  return *this;
}
Vector Vector::operator-() const {
  return {-vector_x_, -vector_y_};
}
Vector Vector::operator+(const Vector right) const {
  return {vector_x_ + right.vector_x_, vector_y_ + right.vector_y_};
}
Vector Vector::operator-(const Vector right) const {
  return {vector_x_ - right.vector_x_, vector_y_ - right.vector_y_};
}
Vector Vector::operator*(int64_t parameter) const {
  return {vector_x_ * parameter, vector_y_ * parameter};
}
Vector Vector::operator/(int64_t parameter) const {
  return {vector_x_ / parameter, vector_y_ / parameter};
}
Vector& Vector::operator+=(const Vector& right) {
  vector_x_ += right.vector_x_;
  vector_y_ += right.vector_y_;
  return *this;
}
Vector& Vector::operator-=(const Vector& right) {
  vector_x_ -= right.vector_x_;
  vector_y_ -= right.vector_y_;
  return *this;
}
Vector& Vector::operator*=(int64_t parameter) {
  vector_x_ *= parameter;
  vector_y_ += parameter;
  return *this;
}
Vector& Vector::operator/=(int64_t parameter) {
  vector_x_ /= parameter;
  vector_y_ /= parameter;
  return *this;
}
bool operator==(const Vector& left, const Vector& right) {
  return left.vector_x_ == right.vector_x_ && left.vector_y_ == right.vector_y_;
}
std::string Vector::ToString() const {
  return "Vector(" + std::to_string(vector_x_) + ", " + std::to_string(vector_y_) + ")";
}
int64_t Vector::GetScalarProduct(const Vector right) const {
  return vector_x_ * right.vector_x_ + vector_y_ * right.vector_y_;
}
int64_t GetKosProduct(Vector start_to_end, Vector start_to_point) {
  return start_to_end.GetVectorX() * start_to_point.GetVectorY() -
         start_to_point.GetVectorX() * start_to_end.GetVectorY();
}
}  // namespace geometry