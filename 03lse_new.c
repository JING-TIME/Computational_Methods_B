#include<stdio.h>
#include<math.h>


int main() {
	
	double x[10] = {0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2, 2.25, 2.5};
	double y[10] = {1.284, 1.648, 2.117, 2.718, 3.427, 2.798, 3.534, 4.456,
	5.465, 5.894};
	
	/* cramer rule	*/
	double a1=0, a2=0, b1=0, b2=0, c1=0, c2=0, a, b, lse=0;
	for (int i=0; i<10; i++) {
		a1 += sin(x[i])*sin(x[i]);
		a2 += cos(x[i])*sin(x[i]);
		b1 = a2;
		b2 += cos(x[i])*cos(x[i]);
		c1 += sin(x[i])*y[i];
		c2 += cos(x[i])*y[i];
	}
	a = (c1*b2-b1*c2)/(a1*b2-b1*a2);
	b = (a1*c2-c1*a2)/(a1*b2-b1*a2);

	/* least square estimation */
	for (int i=0; i<10; i++) {
		lse += pow(a*sin(x[i])+b*cos(x[i])-y[i], 2);
//		printf("%lf, %lf\n", x[i], y[i]);
	}
	
	fprintf(stderr, "a = %.15e, b = %.15e, les = %.15e\n", a, b, lse);
	
	return 0;
}
