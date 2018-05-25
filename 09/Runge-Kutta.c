#include <stdio.h>
#include <math.h>
 
#define N 4
#define MIN 0
#define MAX 1.5

double f(double x, double y) {
	return -x*x*y*y;
}

int main() {
	double h, y0, y1, x0, x1, k1, k2, k3, k4, y;
	double err[N], ok[N];
	for (int l=0; l<N; l++) {
		x0 = 0.0;
		y0 = 3.0;
		h = 0.1/pow(2,l);
		for (int k=0; k<(MAX-MIN)/h; k++) {
			k1 = f(x0, y0);
			k2 = f(x0+0.5*h, y0+0.5*h*k1);
			k3 = f(x0+0.5*h, y0+0.5*h*k2);
			k4 = f(x0+h, y0+h*k3);
			y1 = y0 + h*(k1+2*k2+2*k3+k4)/6;
			x1 = x0 + h;

			x0 = x1;
			y0 = y1;
		
//			printf("x0 %lf, y0 %lf\n", x0, y0);
		}
		y = 3/(1+pow(x0, 3));
//		printf("y %lf\n", y);
		err[l] = fabs(y-y0);
	}
	for (int l=0; l<N-1; l++) {
		ok[l] = log(err[l]/err[l+1])/log(2);
	}
	ok[N-1] = NAN;
	for (int l=0; l<N; l++) {
		printf("h = %lf, err = %le, ok = %lf\n", 0.1/pow(2,l), err[l], ok[l]);
	}
	return 0;
}
