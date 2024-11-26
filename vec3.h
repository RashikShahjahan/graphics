#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
    public:
        float e[3];

        vec3(): e(0,0,0){};
        vec3(float e1,float e2,float e3): e(e1,e2,e3){};

        float x() const {return e[0];}
        float y() const {return e[1];}
        float z() const {return e[2];}

        vec3 operator-() const{return vec3(-e[0],-e[1],-e[2]);}
        float operator[] (int i) const{return e[i];}
        &float operator[] (int i) {return e[i];}

        vec3 operator+= (const vec3 &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
            }
        vec3 operator*= (float t) {
            e[0] *= t;
            e[1] *= t;
            e[2]*= t;
            return *this;
        }
        vec3 operator/= (float t) {
            return *this*=1/t;

        }

        float length() const {
           return  std::sqrt(length_squared());
        }

        float length_squared() const {
           return  e[0]*e[0] +  e[1]*e[1] +  e[2]*e[2];
        }
};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream& out, vec3& v ){
    return out << v.e[0] << ' ' v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(vec3& u ,vec3& v ){
    return vec3(u.e[0]+v.e[0], u.e[1]+v.e[1], u.e[2]+v.e[2]);
}

inline vec3 operator-(vec3& u ,vec3& v ){
    return vec3(u.e[0]-v.e[0], u.e[1]-v.e[1], u.e[2]-v.e[2]);
}

inline vec3 operator*(vec3& u ,vec3& v ){
    return vec3(u.e[0]*v.e[0], u.e[1]*v.e[1], u.e[2]*v.e[2]);
}

inline vec3 operator*(vec3& v ,float t ){
    return v*t;
}

inline vec3 operator/(vec3& v ,float t ){
    return v/t;
}

inline float dot(vec3& u ,vec3& v){
    return u.e[0]*v.e[0] + u.e[1]*v.e[1] + u.e[2]*v.e[2];
}

inline vec3 cross(vec3& u ,vec3& v){
        return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

#endif