#pragma once

#include <Ray.hpp>
#include <Vec3.hpp>

class Camera {
 public:
  Camera();
  Ray get_ray(float u, float v);

 private:
  Vec3 _origin;
  Vec3 _lower_left_corner;
  Vec3 _horizontal;
  Vec3 _vertical;
};