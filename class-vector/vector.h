#ifndef VECTOR_H
#define VECTOR_H


class Vector
{   double _x, _y, _z;
public:
	Vector(double x, double y, double z);
	Vector();
	friend Vector operator+(Vector vect1, Vector vect2);
	friend Vector operator-(Vector vect1, Vector vect2);
	friend double operator*(Vector vect1, Vector vect2);
	friend Vector vect_mult(Vector vect1, Vector vect2);
	friend Vector operator*(Vector vect1, double a);
	friend Vector operator*(double a, Vector vect1);
	friend Vector operator/(Vector vect1, double a);
	friend double abs(Vector vect1);
	double abs();
	double get_x();
	double get_y();
	double get_z();
	friend ostream & vector_print (ostream & outs, Vector vect1);
	~Vector();
};


#endif // VECTOR_H
