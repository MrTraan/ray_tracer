#pragma once
#include <Hitable.hpp>
#include <vector>

class HitableManager : public Hitable {
 public:
  HitableManager() {}

  void add(Hitable* h) { _hitables.push_back(h); }
  virtual bool hit(const Ray& r, float t_min, float t_max,
                   hit_record& rec) const;

 private:
  std::vector<Hitable*> _hitables;
};