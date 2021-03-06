#include <Camera.hpp>

Camera::Camera()
    : _origin(0.0, 0.0, 0.0),
      _lower_left_corner(-2.0, -1.0, -1.0),
      _horizontal(4.0, 0.0, 0.0),
      _vertical(0.0, 2.25, 0.0) {}

Ray Camera::get_ray(float u, float v) {
  return Ray(_origin,
             _lower_left_corner + u * _horizontal + v * _vertical - _origin);
}