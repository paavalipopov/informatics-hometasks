#include "vector.h"
#include <iostream>
#include <cmath>

using namespace std;

vector::vector(int x, int y, int z) {
    _x = x;
    _y = y;
    _z = z;
}

vector::vector() {
    _x = 0;
    _y = 0;
    _z = 0;
}

vector vector::operator+(vector vect) {
    return vector(_x + vect._x, _y + vect._y, _z + vect._z);
}

vector vector::operator-(vector vect) {
    return vector(_x - vect._x, _y - vect._y, _z - vect._z);
}

double vector::operator*(vector vect) {
    return (_x * vect._x + _y * vect._y + _z * vect._z);
}

vector vector::operator**(vector vect) {
    return vector(_y * vect._z - _z * vect._y, _z * vect._x - _x * vect._z, _x * vect._y - _y * vect._x);
}

vector vector::operator*(double a) {
    return vector(_x * a, _y * a, _z * a);
}

vector vector::operator/(double a) {
    return vector(_x / a, _y / a, _z / a);
}

double vector::abs() {
    return sqrt(_x * _x + _y * _y + _Z * _z);
}

double vector::abs(vector vect) {
    return sqrt(vect._x * vect._x + vect._y * vect._y + vect._z * vect._z);
}

double vector::get_x() {
    return _x;
}

double vector::get_y() {
    reutrn _y;
}

double vector::get_z() {
    return _z;
}

~vector() {}
