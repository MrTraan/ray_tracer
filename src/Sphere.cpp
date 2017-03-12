#include <Sphere.hpp>

bool Sphere::hit(const Ray& r,
                 float t_min,
                 float t_max,
                 hit_record& rec) const {
  Vec3 oc = r.origin() - _center;
  float a = dot(r.direction(), r.direction());
  float b = 2.0 * dot(oc, r.direction());
  float c = dot(oc, oc) - _radius * _radius;
  float discriminant = b * b - 4 * a * c;

  if (discriminant > 0) {
    float temp = (-b - sqrt(discriminant)) / (2.0 * a);
    if (temp < t_max && temp > t_min) {
      rec.t = temp;
      rec.p = r.point_at_parameter(temp);
      rec.normal = (rec.p - _center) / _radius;
      return true;
    }
    temp = (-b + sqrt(discriminant)) / (2.0 * a);
    if (temp < t_max && temp > t_min) {
      rec.t = temp;
      rec.p = r.point_at_parameter(temp);
      rec.normal = (rec.p - _center) / _radius;
      return true;
    }
  }
  return false;
}