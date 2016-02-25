#include <iostream>
int convert(int num){
	int k = 1;
	int num2 = 0;

	while (num > 1) {
		num2 = num2 + k*(num % 2);
		num = num / 2;
		k = 10 * k;
	}
	num2 = num2 + k;
	return num2;
}

int main()
{
	int num;
	scanf("%d", &num);
	printf("%d",convert(num));

	getchar();
	return 0;
}


