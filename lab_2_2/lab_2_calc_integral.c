#include<stdlib.h>  //директива препроцесора
#include<stdio.h>
#include<math.h>
#include"lab_2_calc_integral.h"

double myFunction(double x) {		
	return pow(x, 2) + 2 * x;
}

double method_A(double firstArgument, double lastArgument, int precision) {
	double segmentValue = (lastArgument - firstArgument) / precision; //довжина сегменту
	double functionResult;          //висота сегменту
	double sum = 0;               //сума площ сегментів(результат розрахунку)
	double x = firstArgument;

	while (x <= lastArgument - segmentValue) {
		functionResult = myFunction(x);
		sum += functionResult;
		x += segmentValue;
	}

	return segmentValue * sum; //площа сегментів
}

double method_B(double firstArgument, double lastArgument, int precision) {
	double segmentValue = (lastArgument - firstArgument) / precision; //довжина сегменту
	double functionResult;          //висота сегменту
	double sum = 0;               //сума площ сегментів(результат розрахунку)
	double x = firstArgument + segmentValue;

	while (x <= lastArgument) {
		functionResult = myFunction(x);
		sum += functionResult;
		x += segmentValue;
	}

	return segmentValue * sum; //площа сегментів
}

double method_C(double firstArgument, double lastArgument, int precision) {
	double segmentValue = (lastArgument - firstArgument) / precision;
	double functionResult1;
	double functionResult2;
	double sum = 0;
	double x = firstArgument;

	while (x <= lastArgument) {
		functionResult1 = myFunction(x);
		x += segmentValue;
		functionResult2 = myFunction(x);
		sum += (functionResult1 + functionResult2) / 2;
	}

	return segmentValue * sum;
}

double method_D(double firstArgument, double lastArgument, int precision) {
	double segmentValue = (lastArgument - firstArgument) / precision;
	double x0 = firstArgument;
	double xn = lastArgument;
	double x = firstArgument + segmentValue;
	double sumOdd = 0; //сума непарних складових
	double sumEven = 0; //сума парних складових
	int k = 1;

	do {
		sumOdd += myFunction(x);
		x += 2 * segmentValue;
		k += 2;
	} while (k <= precision - 1);

	k = 2;
	x = firstArgument + 2 * segmentValue;

	do {
		sumEven += myFunction(x);
		x += 2 * segmentValue;
		k += 2;
	} while (k <= precision - 2);

	return (segmentValue / 3) * (myFunction(x0) + 4 * sumOdd + 2 * sumEven + myFunction(xn));
}


double calculateByMethod(int methodNumber, float firstArgument, float lastArgument, int precision) {
	if (methodNumber == 1) {
		return method_A(firstArgument, lastArgument, precision);
	}
	if (methodNumber == 2) {
		return method_B(firstArgument, lastArgument, precision);
	}
	if (methodNumber == 3) {
		return method_C(firstArgument, lastArgument, precision);
	}
	if (methodNumber == 4) {
		return method_D(firstArgument, lastArgument, precision);
	}
}