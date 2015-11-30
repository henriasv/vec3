#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <random>

class vec3
{
public:
    vec3();
    vec3(double, double, double);
    //vec3(const vec3& w) { data[0] = w.data[0], data[1] = w.data[1],data[2] = w.data[2]; }
    ~vec3();
    void setX(double);
    void setY(double);
    void setZ(double);

    double x();
    double y();
    double z();

    double *dataptr();

    void randnormalized();
    void randbox();
    void floor();

    double norm();
    double sqnorm();

    double prod();

    static std::random_device rd;
    static std::mt19937 gen;

    vec3 operator+(const vec3 &);
    vec3 operator-(const vec3 &);
    vec3 operator*(const vec3 &);
    vec3 operator/(const vec3 &);

    vec3 operator/(const double &);
    vec3 operator*(const double &);

    vec3 & operator*=(const vec3 &);
    vec3 & operator+=(const vec3 &);

    vec3 & operator-=(const double &);
    vec3 & operator/=(const double &);
    vec3 & operator*=(const double &);

    inline double &operator[](int index) { return data[index]; }
    inline double operator[](int index) const { return data[index]; }

    friend std::ostream & operator << (std::ostream &, const vec3 &);

private:
    double data[3];

};


#endif // VEC3_H
