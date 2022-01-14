#include "vec3.h"
#include <cmath>


std::random_device vec3::rd;
std::normal_distribution<> vec3::randn(0,1);
std::uniform_int_distribution<> vec3::randint;
std::uniform_real_distribution<double> vec3::randu(0,1.0);
std::mt19937 vec3::gen(vec3::rd());


vec3::vec3() : m_x(0), m_y(0), m_z(0)
{
}

vec3::vec3(double x, double y, double z) : m_x(x), m_y(y), m_z(z)
{

}

double vec3::x() const
{
    return m_x;
}

double vec3::y() const
{
    return m_y;
}

double vec3::z() const
{
    return m_z;
}

void vec3::randsphere()
{
    double r = (double) std::generate_canonical<double, 10>(gen);
    r = pow(r, 1.0/3);
    vec3 direction((double) randn(gen), (double) randn(gen), (double) randn(gen));
    direction = direction/direction.norm()*r;
    m_x = direction.m_x;
    m_y = direction.m_y;
    m_z = direction.m_z;
}

void vec3::randbox()
{
    m_x = (double) std::generate_canonical<double, 10>(gen);
    m_y = (double) std::generate_canonical<double, 10>(gen);
    m_z = (double) std::generate_canonical<double, 10>(gen);
}

void vec3::floor()
{
    m_x = ::floor(m_x);
    m_y = ::floor(m_y);
    m_z = ::floor(m_z);
}

double vec3::norm()
{
    return sqrt(m_x*m_x+m_y*m_y+m_z*m_z);
}

double vec3::sqnorm()
{
    return m_x*m_x+m_y*m_y+m_z*m_z;
}

vec3 vec3::operator+(const vec3 & other) const 
{
    return vec3(this->m_x + other.m_x,
                this->m_y + other.m_y,
                this->m_z + other.m_z);
}


vec3 vec3::operator-(const vec3 & other) const {
    return vec3(this->m_x - other.m_x,
                this->m_y - other.m_y,
                this->m_z - other.m_z);
}

vec3& vec3::operator/=(const double & other)
{
    m_x/=other;
    m_y/=other;
    m_z/=other;
    return *this;
}

vec3& vec3::operator*=(const double & other)
{
    m_x*=other;
    m_y*=other;
    m_z*=other;
    return *this;
}

vec3 vec3::operator*(const vec3& other) const
{
    return vec3(this->m_x * other.m_x,
                this->m_y * other.m_y,
            this->m_z * other.m_z);
}

vec3 vec3::operator/(const vec3 & other) const
{
    return vec3(this->m_x / other.m_x,
                this->m_y / other.m_y,
                this->m_z / other.m_z);
}

vec3 vec3::operator/(const double & other) const
{
    return vec3(m_x/other, m_y/other, m_z/other);
}

vec3 vec3::operator*(const double & other) const 
{
    return vec3(m_x*other, m_y*other, m_z*other);
}

vec3 & vec3::operator*=(const vec3 & other)
{
    m_x*=other.m_x;
    m_y*=other.m_y;
    m_z*=other.m_z;
    return *this;
}

vec3 &vec3::operator+=(const vec3 & other)
{
    m_x+=other.m_x;
    m_y+=other.m_y;
    m_z+=other.m_z;
    return *this;
}

vec3 & vec3::operator-=(const double& other)
{
    m_x -= other;
    m_y -= other;
    m_z -= other;
    return *this;
}

std::ostream & operator <<(std::ostream &os, const vec3& vec)
{
    os << vec.x() << " " << vec.y() << " " << vec.z();
    return os;
}

void vec3::setX(double arg_x)
{
    m_x = arg_x;
}

void vec3::setY(double arg_y)
{
    m_y = arg_y;
}

void vec3::setZ(double arg_z)
{
    m_z = arg_z;
}
