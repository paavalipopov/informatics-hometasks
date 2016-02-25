#ifndef VECTOR_H
#define VECTOR_H


class vector
{   double _x, _y, _z;
public:
    vector(double x, double y, double z);
    vector();
    friend vector operator+(vector vect1, vector vect2);
    friend vector operator-(vector vect1, vector vect2);
    friend double operator*(vector vect1, vector vect2);
    friend vector vect_mult(vector vect1, vector vect2);
    friend vector operator*(vector vect1, double a);
    friend vector operator/(vector vect1, double a);
    friend double abs(vector vect1);
    double abs();
    double get_x();
    double get_y();
    double get_z();
    friend ostream & vect_print (ostream & outs, vector vect1);
    ~vector();
};


#endif // VECTOR_H
