#ifndef MATRIX_H
#define MATRIX_H

#include "../class-vector/vector.h"


class Matrix
{   double _x[3], _y[3], _z[3];
public:
	Matrix(double x0, double x1, double x2,
		   double y0, double y1, double y2,
		   double z0, double z1, double z2);
	Matrix(Vector vect1, Vector vect1, Vector vect1);
	Matrix();
	friend Matrix operator+(Matrix matrix1, Matrix matrix2);
	friend Matrix operator-(Matrix matrix1, Matrix matrix2);
	friend Matrix operator*(Matrix matrix1, Matrix matrix2);
	friend Matrix operator*(Matrix matrix1, Vector vect1);
	friend Vector operator*(Vector vect1, Matrix matrix1);
	friend Vector operator*(Matrix matrix1, double a);
	friend Matrix operator*(double a, Matrix matrix1);
	friend Matrix operator/(Matrix matrix1, double a);
	Matrix transposition();
	double determinant();
	friend ostream & matrix_print (ostream & outs, Matrix matrix1);
	~vector();
};


#endif // VECTOR_H
