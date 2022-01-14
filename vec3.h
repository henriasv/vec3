#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <random>
#include <string>

class vec3
{
public:
    vec3();
    vec3(double, double, double);
    
    //vec3(const vec3& w);
    //~vec3();

    void setX(double);
    void setY(double);
    void setZ(double);

    double x() const;
    double y() const;
    double z() const;

    void randnormalized();
    void randsphere();
    void randbox();
    void floor();

    double norm();
    double sqnorm();

    static std::random_device rd;
    static std::normal_distribution<> randn;
    static std::uniform_real_distribution<> randu;
    static std::uniform_int_distribution<> randint;
    static std::mt19937 gen;

    vec3 operator+(const vec3 &) const;
    vec3 operator-(const vec3 &) const;
    vec3 operator*(const vec3 &) const;
    vec3 operator/(const vec3 &) const;

    vec3 operator/(const double &) const;
    vec3 operator*(const double &) const;

    vec3 & operator*=(const vec3 &);
    vec3 & operator+=(const vec3 &);

    vec3 & operator-=(const double &);
    vec3 & operator/=(const double &);
    vec3 & operator*=(const double &);

    //inline double &operator[](int index) { return data[index]; }
    //inline double operator[](int index) const { return data[index]; }

    friend std::ostream & operator << (std::ostream &, const vec3 &);

private:
    double m_x;
    double m_y;
    double m_z;
};


#endif // VEC3_H
