#include <Ray.hpp>
#include <Vec3.hpp>
#include <Hitable.hpp>
#include <Sphere.hpp>
#include <Window.hpp>
#include <iostream>
#include <float.h>

Vec3 color(const Ray &r, Hitable &target) {
  hit_record rec;
  if (target.hit(r, 0.0, MAXFLOAT, rec)) {
    return 0.5 * Vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
  } else {
    Vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
  }
}

int main(void) {
  Window::Window window;

  int nx = 200;
  int ny = 100;

  Vec3 lower_left_corner(-2.0, -1.0, -1.0);
  Vec3 horizontal(4.0, 0.0, 0.0);
  Vec3 vertical(0.0, 2.0, 0.0);
  Vec3 origin(0.0, 0.0, 0.0);

  Sphere s(Vec3(0,0,-1), 0.5);

  for (int j = 0; j < ny; j++) {
    for (int i = 0; i < nx; i++) {
      float u = float(i) / float(nx);
      float v = float(ny - j) / float(ny);
      Ray r(origin, lower_left_corner + u * horizontal + v * vertical);

      Vec3 col = color(r, s);
      int ir = int(255.99 * col.r());
      int ig = int(255.99 * col.g());
      int ib = int(255.99 * col.b());

      sf::Color color(ir, ig, ib);
      window.putPixel(i, j, color);
    }
  }

  window.display();
  return (0);
}