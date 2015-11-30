#include "vec3.h"
#include <cmath>


std::random_device vec3::rd;
std::mt19937 vec3::gen(vec3::rd());


vec3::vec3() : data{0, 0, 0}
{
}

vec3::vec3(double x, double y, double z) : data{x, y, z}
{

}

vec3::~vec3()
{

}

double vec3::x()
{
    return data[0];
}

double vec3::y()
{
    return data[1];
}

double vec3::z()
{
    return data[2];
}

double *vec3::dataptr()
{
    return data;
}

void vec3::randnormalized()
{
    data[0] = (double) 2*std::generate_canonical<double, 10>(gen);//rand()/RAND_MAX*2;
    data[1] = (double) 2*std::generate_canonical<double, 10>(gen);
    data[2] = (double) 2*std::generate_canonical<double, 10>(gen);
    (*this) -= 1.0;
    (*this) /= this->norm();
}

void vec3::randbox()
{
    data[0] = (double) std::generate_canonical<double, 10>(gen);
    data[1] = (double) std::generate_canonical<double, 10>(gen);
    data[2] = (double) std::generate_canonical<double, 10>(gen);
}

void vec3::floor()
{
    data[0] = ::floor(data[0]);
    data[1] = ::floor(data[1]);
    data[2] = ::floor(data[2]);
}

bool vec3::inBox(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)
{
    return ((data[0] > xmin) && (data[0] < xmax) && (data[1] > ymin) && (data[1] < ymax) && (data[2] > zmin) && (data[2] < zmax));
}

double vec3::norm()
{
    return sqrt(data[0]*data[0]+data[1]*data[1]+data[2]*data[2]);
}

double vec3::sqnorm()
{
    return data[0]*data[0]+data[1]*data[1]+data[2]*data[2];
}

double vec3::prod()
{
    return data[0]*data[1]*data[2];
}

double vec3::sum()
{
    return data[0]+data[1]+data[2];
}

vec3 vec3::operator+(const vec3 & other)
{
    return vec3(this->data[0] + other.data[0],
                this->data[1] + other.data[1],
                this->data[2] + other.data[2]);
}

vec3 vec3::operator-(const vec3 & other)
{
    return vec3(this->data[0] - other.data[0],
                this->data[1] - other.data[1],
                this->data[2] - other.data[2]);
}

vec3& vec3::operator/=(const double & other)
{
    data[0]/=other;
    data[1]/=other;
    data[2]/=other;
    return *this;
}

vec3& vec3::operator*=(const double & other)
{
    data[0]*=other;
    data[1]*=other;
    data[2]*=other;
    return *this;
}

vec3 vec3::operator*(const vec3& other)
{
    return vec3(this->data[0] * other.data[0],
                this->data[1] * other.data[1],
            this->data[2] * other.data[2]);
}

vec3 vec3::operator/(const vec3 & other)
{
    return vec3(this->data[0] / other.data[0],
                this->data[1] / other.data[1],
                this->data[2] / other.data[2]);
}

vec3 vec3::operator/(const double & other)
{
    return vec3(data[0]/other, data[1]/other, data[2]/other);
}

vec3 vec3::operator*(const double & other)
{
    return vec3(data[0]*other, data[1]*other, data[2]*other);
}

vec3 & vec3::operator*=(const vec3 & other)
{
    data[0]*=other.data[0];
    data[1]*=other.data[1];
    data[2]*=other.data[2];
    return *this;
}

vec3 &vec3::operator+=(const vec3 & other)
{
    data[0]+=other.data[0];
    data[1]+=other.data[1];
    data[2]+=other.data[2];
    return *this;
}

vec3 & vec3::operator-=(const double& other)
{
    data[0] -= other;
    data[1] -= other;
    data[2] -= other;
    return *this;
}

std::ostream & operator <<(std::ostream &os, const vec3& vec)
{
    os << vec.data[0] << " " << vec.data[1] << " " << vec.data[2];
    return os;
}

void vec3::setX(double arg_x)
{
    data[0] = arg_x;
}

void vec3::setY(double arg_y)
{
    data[1] = arg_y;
}

void vec3::setZ(double arg_z)
{
    data[2] = arg_z;
}
