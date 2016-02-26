#include "matrix.h"
#include "../class-vector/vector.h"
#include <iostream>
#include <cmath>

using namespace std;

Matrix::Matrix(double x0, double x1, double x2,
			   double y0, double y1, double y2,
			   double z0, double z1, double z2) {
	_x[0] = x0;
	_x[1] = x1;
	_x[2] = x2;

	_y[0] = y0;
	_y[1] = y1;
	_y[2] = y2;

	_z[0] = z0;
	_z[1] = z1;
	_z[2] = z2;
}

Matrix::Matrix(Vector vect1, Vector vect2, Vector vect3){
	_x[0] = vect1.get_x();
	_x[1] = vect2.get_x();
	_x[2] = vect3.get_x();

	_y[0] = vect1.get_x();
	_y[1] = vect2.get_y();
	_y[2] = vect3.get_y();

	_z[0] = vect1.get_z();
	_z[1] = vect2.get_z();
	_z[2] = vect3.get_z();
}

Matrix::Matrix() {
	_x = {0, 0, 0};
	_y = {0, 0, 0};
	_z = {0, 0, 0};
}

Matrix operator+(Matrix matrix1, Matrix matrix2) {
	return Matrix(matrix1._x[0] + matrix2._x[0],
			matrix1._x[1] + matrix2._x[1],
			matrix1._x[2] + matrix2._x[2],
			matrix1._y[0] + matrix2._y[0],
			matrix1._y[1] + matrix2._y[1],
			matrix1._y[2] + matrix2._y[2],
			matrix1._z[0] + matrix2._z[0],
			matrix1._z[0] + matrix2._z[0],
			matrix1._z[0] + matrix2._z[0],);
}

Matrix operator-(Matrix matrix1, Matrix matrix2) {
	return Matrix(
		matrix1._x[0] + matrix2._x[0],
		matrix1._x[1] - matrix2._x[1],
		matrix1._x[2] - matrix2._x[2],
		matrix1._y[0] - matrix2._y[0],
		matrix1._y[1] - matrix2._y[1],
		matrix1._y[2] - matrix2._y[2],
		matrix1._z[0] - matrix2._z[0],
		matrix1._z[0] - matrix2._z[0],
		matrix1._z[0] - matrix2._z[0]);
}

Matrix operator*(Matrix matrix1, Matrix matrix2) {
	return Matrix(
		matrix1._x[0]*matrix2._x[0] + matrix1._x[1]*matrix2._y[0] + matrix1._x[2]*matrix2._z[0],
		matrix1._x[0]*matrix2._x[1] + matrix1._x[1]*matrix2._y[1] + matrix1._x[2]*matrix2._z[1],
		matrix1._x[0]*matrix2._x[2] + matrix1._x[1]*matrix2._y[2] + matrix1._x[2]*matrix2._z[2],
		matrix1._y[0]*matrix2._x[0] + matrix1._y[1]*matrix2._y[0] + matrix1._y[2]*matrix2._z[0],
		matrix1._y[0]*matrix2._x[1] + matrix1._y[1]*matrix2._y[1] + matrix1._y[2]*matrix2._z[1],
		matrix1._y[0]*matrix2._x[2] + matrix1._y[1]*matrix2._y[2] + matrix1._y[2]*matrix2._z[2],
		matrix1._z[0]*matrix2._x[0] + matrix1._z[1]*matrix2._y[0] + matrix1._z[2]*matrix2._z[0],
		matrix1._z[0]*matrix2._x[1] + matrix1._z[1]*matrix2._y[1] + matrix1._z[2]*matrix2._z[1],
		matrix1._z[0]*matrix2._x[2] + matrix1._z[1]*matrix2._y[2] + matrix1._z[2]*matrix2._z[2]);
}

Vector operator*(Matrix matrix1, Vector vect1) {
	return Vector(
		matrix1._x[0]*vect1.get_x() + matrix1._x[1]*vect1.get_y() + matrix1._x[2]*vect1.get_z(),
		matrix1._y[0]*vect1.get_x() + matrix1._y[1]*vect1.get_y() + matrix1._y[2]*vect1.get_z(),
		matrix1._z[0]*vect1.get_x() + matrix1._z[1]*vect1.get_y() + matrix1._z[2]*vect1.get_z());
}

Vector operator*(Vector vect1, Matrix matrix1){
	return Vector(
		matrix1._x[0]*vect1.get_x() + matrix1._x[1]*vect1.get_y() + matrix1._x[2]*vect1.get_z(),
		matrix1._y[0]*vect1.get_x() + matrix1._y[1]*vect1.get_y() + matrix1._y[2]*vect1.get_z(),
		matrix1._z[0]*vect1.get_x() + matrix1._z[1]*vect1.get_y() + matrix1._z[2]*vect1.get_z());
}

Matrix operator*(Matrix matrix1, double a){
	return Matrix(
			matrix1.x[0] * a, matrix1.x[1] * a, matrix1.x[2] * a,
			matrix1.y[0] * a, matrix1.y[1] * a, matrix1.y[2] * a,
			matrix1.z[0] * a, matrix1.z[1] * a, matrix1.z[2] * a);
}

Matrix operator*(double a, Matrix matrix1) {
	return Matrix(
			matrix1.x[0] * a, matrix1.x[1] * a, matrix1.x[2] * a,
			matrix1.y[0] * a, matrix1.y[1] * a, matrix1.y[2] * a,
			matrix1.z[0] * a, matrix1.z[1] * a, matrix1.z[2] * a);
}

Matrix operator/(Matrix matrix1, double a) {
	return Matrix(
			matrix1.x[0] / a, matrix1.x[1] / a, matrix1.x[2] / a,
			matrix1.y[0] / a, matrix1.y[1] / a, matrix1.y[2] / a,
			matrix1.z[0] / a, matrix1.z[1] / a, matrix1.z[2] / a);
}

Matrix Matrix::transposition() {
	return Matrix(
		matrix1.x[0], matrix1.y[0], matrix1.z[0],
		matrix1.x[1], matrix1.y[1], matrix1.z[1],
		matrix1.x[2], matrix1.y[2], matrix1.z[2]);
}

double Matrix::determinant() {
	return (matrix1.x[0] * (matrix1.y[1] * matrix1.z[2] - matrix1.y[2] * matrix1.z[1]) -
			matrix1.x[1] * (matrix1.y[0] * matrix1.z[2] - matrix1.y[2] * matrix1.z[0]) +
			matrix1.x[2] * (matrix1.y[0] * matrix1.z[1] - matrix1.y[1] * matrix1.z[0]));
}
ostream & matrix_print (ostream & outs, Matrix matrix1) {
	outs << endl
		 << "\t" << matrix1._x[0] << "\t" << matrix1._x[1] << "\t" << matrix1._x[2] << endl
		 << "\t" << matrix1._y[0] << "\t" << matrix1._y[1] << "\t" << matrix1._y[2] << endl
		 << "\t" << matrix1._z[0] << "\t" << matrix1._z[1] << "\t" << matrix1._z[2] << endl;
}

~vector() {};
