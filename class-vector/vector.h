#ifndef VECTOR_H
#define VECTOR_H


class vector
{   double _x, _y, _z;
public:
    vector(double x, double y, double z);
    vector();
    vector operator+(vector vect);
    vector operator-(vector vect);
    double operator*(vector vect);
    vector vect_mult(vector vect1, vect2);
    vector operator*(double a);
    vector operator/(double a);
    double abs(vector _vect);
    double abs();
    double get_x();
    double get_y();
    double get_z();
    ~vector();
};

#endif // VECTOR_H
