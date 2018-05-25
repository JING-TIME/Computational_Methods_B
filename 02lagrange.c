#include<stdio.h>
#include<math.h>

#define CONST 500
#define PI 3.1415926535897932384626

double fx(double x) {
	double fx =	1/(1+x*x);
	return fx;
}

double func1(int i, int n) {
	return -5+10.0*i/n;
}

double func2(int i, int n) {
	return -5*cos((2*i+1)*PI/(2*n+2));
}

void lagrange(double (*fun)(int, int));

int main() {
	fprintf(stderr, "-5+10i/n\n");
	lagrange(func1);
	fprintf(stderr, "-5cos[(2i+1)PI/(2n+2)]\n");
	lagrange(func2);
	return 0;
}

void lagrange(double (*fun)(int, int)) {

	int ns[4] = {5, 10, 20, 40};
	for (int l=0; l<4; l++) {
		int n = ns[l];
		double xs[n+1];
		double max=0;  
		double fs[n+1];
		double ls[n+1];
		for (int j=0; j<=CONST; j++) {
			double x = func1(j, CONST);
			double lx = 0;
			for (int i=0; i<=n; i++) {
				xs[i] = fun(i, n);
				fs[i] = fx(xs[i]);
			}
			for (int i=0; i<=n; i++) {
				double up = 1, down = 1;
				for (int k=0; k<=n; k++) {
					if (k!=i) {
						up *= x-xs[k];
						down *= xs[i]-xs[k];
					}
				}
				ls[i] = up/down;
				lx += fs[i]*ls[i];
			}
			if (fabs(lx-fx(x))>max)
				max = fabs(lx-fx(x));
			//	printf("%f, %f\n", x, lx);
		}
		fprintf(stderr, "n = %d, max = %.15f\n", n, max);
	}
}








