#include "vector.h"
#include <iostream>
#include <cmath>

using namespace std;

Vector::Vector(double x, double y, double z) {
	_x = x;
	_y = y;
	_z = z;
}

Vector::Vector() {
	_x = 0;
	_y = 0;
	_z = 0;
}

Vector operator+(Vector vect1, Vector vect2) {
	return vector(vect1._x + vect2._x, vect1._y + vect2._y, vect1._z + vect2._z);
}

Vector operator-(Vector vect1, Vector vect2) {
	return Vector(vect1._x - vect2._x, vect1._y - vect2._y, vect1._z - vect2._z);
}

double operator*(Vector vect1, Vector vect2) {
	return (vect1._x * vect2._x + vect1._y * vect2._y + vect1._z * vect2._z);
}

Vector vect_mult(Vector vect1, Vector vect2) {
	return Vector(vect1._y * vect2._z - vect1._z * vect2._y,
				  vect1._z * vect2._x - vect1._x * vect2._z,
				  vect1._x * vect2._y - vect1._y * vect2._x);
}

Vector operator*(Vector vect1, double a) {
	return Vector(vect1._x * a, vect1._y * a, vect1._z * a);
}

Vector operator*(double a, Vector vect1) {
	return Vector(vect1._x * a, vect1._y * a, vect1._z * a);
}

Vector operator/(Vector vect1, double a) {
	return Vector(vect1._x / a, vect1._y / a, vect1._z / a);
}

double Vector::abs() {
	return sqrt(_x * _x + _y * _y + _z * _z);
}

double abs(Vector vect1) {
	return sqrt(vect1._x * vect1._x + vect1._y * vect1._y + vect1._z * vect1._z);
}

double Vector::get_x() {
	return _x;
}

double Vector::get_y() {
	return _y;
}

double Vector::get_z() {
	return _z;
}

friend ostream & vector_print (ostream & outs, Vector vect1) {
	outs << "x = " << vect1._x << "; y = " << vect1._y << "; z = " << vect1._z << endl;
}

Vector::~Vector() {}
