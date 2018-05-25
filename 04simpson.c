#include<stdio.h>
#include<math.h>

#define K 12

int integral(double (*func)(double), double a, double b, double I);

int main() {
	double I = cos(1)-cos(5);   // true value
	integral(sin, 1, 5, I);
	return 0;
}

int integral(double (*func)(double), double a, double b, double I) {
	double h;
	double T[K], S[K], Te[K], Se[K], To[K], So[K];
	int N[K];
	
	for (int i=0; i<K; i++) {
		N[i] = pow(2, i+1);
		long double x[N[i]+1];
		h = (b-a)/N[i];
		T[i] = 0, S[i] = 0;
		for (int j=0; j<=N[i]; j++) {
			x[j] = a+j*h;
		}
		for (int j=0; j<N[i]; j++) {
			T[i] += h/2*(sin(x[j])+sin(x[j+1]));
}
		for (int j=0; j<N[i]/2; j++) {
			S[i] += h/3*(sin(x[2*j])+4*sin(x[2*j+1])+sin(x[2*j+2]));
		}
		Te[i] = fabs(I-T[i]);
		Se[i] = fabs(I-S[i]);
	}
	for (int i=0; i<K-1; i++) {
		To[i] = log(Te[i]/Te[i+1])/log(2);
		So[i] = log(Se[i]/Se[i+1])/log(2);
	}
	To[K-1] = NAN;
	So[K-1] = NAN;

	printf("Trapezoidal integral\n");
	printf("%8s, %8s, %21s, %21s, %21s\n", "k", "N", "T[k]", "e[k]", "o[k]");
	for (int i=0; i<K; i++) {
		printf("%8d, %8d, %.15e, %.15e, %.15e\n",i+1, N[i], T[i], Te[i], To[i]);	
	}
	printf("Simpson integral\n");
	printf("%8s, %8s, %21s, %21s, %21s\n", "k", "N", "S[k]", "e[k]", "o[k]");
	for (int i=0; i<K; i++) {
		printf("%8d, %8d, %.15e, %.15e, %.15e\n",i+1, N[i], S[i], Se[i], So[i]);	
	}

	return 0;
}
