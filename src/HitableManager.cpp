#include <HitableManager.hpp>

bool HitableManager::hit(const Ray& r,
                         float t_min,
                         float t_max,
                         hit_record& rec) const {
  hit_record temp_rec;

  bool hit_anything = false;
  float closest_so_far = t_max;
  std::vector<Hitable*>::const_iterator it = _hitables.begin();
  while (it != _hitables.end()) {
    if ((*it)->hit(r, t_min, closest_so_far, temp_rec)) {
      hit_anything = true;
      closest_so_far = temp_rec.t;
      rec = temp_rec;
    }
    it++;
  }
  return hit_anything;
}