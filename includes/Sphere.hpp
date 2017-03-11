#pragma once

#include <Vec3.hpp>
#include <Hitable.hpp>

class Sphere : public Hitable {
    public:
    Sphere() {}
    Sphere(Vec3 cen, float r) : _center(cen), _radius(r) {};

    virtual bool hit(const Ray &r, float t_min, float t_max, hit_record &rec) const;
    
    Vec3 center() { return _center;}
    float radius() { return _radius;}

    private:
        Vec3 _center;
        float _radius;
};