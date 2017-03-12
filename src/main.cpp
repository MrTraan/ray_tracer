#include <float.h>  /* MAXFLOAT */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <Camera.hpp>
#include <Hitable.hpp>
#include <HitableManager.hpp>
#include <Ray.hpp>
#include <Sphere.hpp>
#include <Vec3.hpp>
#include <Window.hpp>
#include <iostream>

float my_rand() {
  return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

Vec3 random_in_unit_sphere() {
  Vec3 p;

  do {
    p = 2.0 * Vec3(my_rand(), my_rand(), my_rand()) - Vec3(1, 1, 1);
  } while (p.squared_length() >= 1.0);
  return p;
}

Vec3 color(const Ray& r, HitableManager& manager) {
  hit_record rec;

  if (manager.hit(r, 0.001, MAXFLOAT, rec)) {
    Vec3 target = rec.p + rec.normal + random_in_unit_sphere();
    return 0.5 * color(Ray(rec.p, target - rec.p), manager);
  } else {
    Vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
  }
}

int main(void) {
  Window::Window window;
  HitableManager::HitableManager manager;
  Camera::Camera cam;

  srand(time(NULL));

  int nx = WIN_WIDTH;
  int ny = WIN_HEIGHT;
  int ns = 10;

  manager.add(new Sphere(Vec3(0, 0, -1), 0.5));
  manager.add(new Sphere(Vec3(0, -100.5, -1), 100));

  for (int j = 0; j < ny; j++) {
    for (int i = 0; i < nx; i++) {
      Vec3 col(0, 0, 0);
      for (int s = 0; s < ns; s++) {
        float u = float(i + my_rand()) / float(nx);
        float v = float(ny - j + my_rand()) / float(ny);
        Ray r = cam.get_ray(u, v);

        col += color(r, manager);
      }
      col /= float(ns);
      col.lighten_gamma();
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