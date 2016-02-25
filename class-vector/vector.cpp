#include "vector.h"
#include <iostream>
#include <cmath>

using namespace std;

vector::vector(double x, double y, double z) {
    _x = x;
    _y = y;
    _z = z;
}

vector::vector() {
    _x = 0;
    _y = 0;
    _z = 0;
}

vector operator+(vector vect1, vector vect2) {
    return vector(vect1._x + vect2._x, vect1._y + vect2._y, vect1._z + vect2._z);
}

vector operator-(vector vect1, vector vect2) {
    return vector(vect1._x - vect2._x, vect1._y - vect2._y, vect1._z - vect2._z);
}

double operator*(vector vect1, vector vect2) {
    return (vect1._x * vect2._x + vect1._y * vect2._y + vect1._z * vect2._z);
}

vector vect_mult(vector vect1, vector vect2) {
    return vector(vect1._y * vect2._z - vect1._z * vect2._y, vect1._z * vect2._x - vect1._x * vect2._z, vect1._x * vect2._y - vect1._y * vect2._x);
}

vector operator*(vector vect1, double a) {
    return vector(vect1._x * a, vect1._y * a, vect1._z * a);
}

vector operator/(vector vect1, double a) {
    return vector(vect1._x / a, vect1._y / a, vect1._z / a);
}

double vector::abs() {
    return sqrt(_x * _x + _y * _y + _z * _z);
}

double abs(vector vect1) {
    return sqrt(vect1._x * vect1._x + vect1._y * vect1._y + vect1._z * vect1._z);
}

double vector::get_x() {
    return _x;
}

double vector::get_y() {
    return _y;
}

double vector::get_z() {
    return _z;
}

friend ostream & vect_print (ostream & outs, vector vect1) {
	outs << "x = " << vect1._x << "; y = " << vect1._y << "; z = " << vect1._z << endl;
}

vector::~vector() {}
