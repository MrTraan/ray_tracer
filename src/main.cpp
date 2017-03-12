#include <float.h>
#include <Hitable.hpp>
#include <HitableManager.hpp>
#include <Ray.hpp>
#include <Sphere.hpp>
#include <Vec3.hpp>
#include <Window.hpp>
#include <iostream>

Vec3 color(const Ray& r, HitableManager& manager) {
  hit_record rec;
  if (manager.hit(r, 0.0, MAXFLOAT, rec)) {
    return 0.5 *
           Vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
  } else {
    Vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
  }
}

int main(void) {
  Window::Window window;
  HitableManager::HitableManager manager;

  int nx = WIN_WIDTH;
  int ny = WIN_HEIGHT;

  Vec3 lower_left_corner(-2.0, -1.0, -1.0);
  Vec3 horizontal(4.0, 0.0, 0.0);
  Vec3 vertical(0.0, 2.25, 0.0);
  Vec3 origin(0.0, 0.0, 0.0);

  manager.add(new Sphere(Vec3(0, 0, -1), 0.5));
  manager.add(new Sphere(Vec3(0, -100.5, -1), 100));

  for (int j = 0; j < ny; j++) {
    for (int i = 0; i < nx; i++) {
      float u = float(i) / float(nx);
      float v = float(ny - j) / float(ny);
      Ray r(origin, lower_left_corner + u * horizontal + v * vertical);

      Vec3 col = color(r, manager);
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