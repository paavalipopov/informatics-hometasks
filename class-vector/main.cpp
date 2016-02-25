#include <iostream>
#include "vector.h"
using namespace std;



int main(void) {
	vector A(1, 2, 3);
	vector B(2, 3, 4);
	vector C;
	C = A + B;
	
	cout<< "x = " << C.get_x() << "; y = " << C.get_y() << "; z = " << C.get_z() << endl;
	return 0;
}
