#include <stdio.h>
#include <math.h>

#define N 4 

// function to solve, f(x) == 0
double func1(double x) {
	return (x*x*x/3-x);
}

// derivative function, f'(x)
double func2(double x) {
	return (x*x - 1);
}

// Newton method
int Newton(
		double (*func)(double), double (*D_func)(double), 
		double x_init, double err) {
	int step = 0;
	double x0 = x_init, x1;

	while (1) {
		if (fabs(func(x0)) < err) {
			printf("x0 = %0.1lf, root = %0.15le, step = %d\n", x_init, x0, step);
			break;
		}
		x1 = x0 - func(x0)/D_func(x0);  // iteration formula
		x0 = x1;
		step ++;
	}

	return 0;
}

// Secant method
int Secant( double (*func)(double), double x_init[], double err) {
	int step = 0;
	double x0 = x_init[0], x1 = x_init[1], x2;

	while (1) {
		if ( fabs(func(x1)) < err) {
			printf("x0 = %0.1lf, x1 = %0.1lf, root = %0.15le, step = %d\n",
			x_init[0], x_init[1], x1, step);
			break;
		}
		x2 = x1 - func(x1)*(x1-x0)/(func(x1)-func(x0)); // iteration formula
		x0 = x1;
		x1 = x2;
		step ++;
	}	
	return 0;
}

int main() {
	double array1[] = {0.1, 0.2, 0.9, 9.0};
	double array2[][2] = {{-0.1,0.1},{-0.2,0.2},{-2.0,0.9},{0.9,9.0}};
	double err = 1.0e-8;
	
	printf("Newton Method\n");
	for (int i=0; i<N; i++) {
		Newton(func1, func2, array1[i], err);
	}

	printf("Secant Method\n");
	for (int i=0; i<N; i++) {
		Secant(func1, array2[i], err);
	}
	
	return 0;
}
