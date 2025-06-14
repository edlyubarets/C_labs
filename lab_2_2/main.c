#include<stdlib.h>  //директива препроцесора
#include<stdio.h>
#include<math.h>
#include"lab_2_calc_integral.h"


int main() {
	float firstArgument = -1.4;
	float lastArgument = 3.14;
	int method;
	int precision;
	double result;
	double delta = 100;
	double L1;
	double L2;

	//вибір методу інтегрування
	while (1) {
		printf("Enter calculation method (1 - 4)\n");
		scanf_s("%u", &method);
		if (method < 1 || method > 4) {
			printf("Method is not supported\n");
		}
		else {
			break;
		}
	}

	//налаштування точності інтегрування
	printf("Enter segments number\n");
	scanf_s("%u", &precision);

	//перевірка похибки
	do {
		L1 = calculateByMethod(method, firstArgument, lastArgument, precision);
		precision += 2;
		L2 = calculateByMethod(method, firstArgument, lastArgument, precision);
		delta = abs(L1 - L2);
		//printf("delta = %lf\n", delta);
	} while (delta > 0.001 || delta > 0.00001);
	precision -= 2;
	
	//вивід результату інтегралу
	printf("result = %lf, precision = %u\n", L2, precision);

	return 0;
}
