#pragma once
#include <Vec3.hpp>

class Ray {
 public:
  Ray() {}
  Ray(const Vec3& a, const Vec3& b) : _origin(a), _direction(b) {}
  Vec3 origin() const { return _origin; }
  Vec3 direction() const { return _direction; }
  Vec3 point_at_parameter(float t) const { return _origin + t * _direction; }

 private:
  Vec3 _origin;
  Vec3 _direction;
};