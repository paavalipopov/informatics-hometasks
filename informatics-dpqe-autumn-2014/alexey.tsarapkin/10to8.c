#include<stdio.h>

int main(){

	int x=0,y=0,z=1;

	scanf("%d", &x);
	
	while (x>7) {
		y=y+z*(x%8);
		x/=8;
		z*=10;
		}
	y=x*z+y;
	printf("%d\n", y);

return 0;
}
