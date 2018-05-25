#include <stdio.h>
#include <math.h>

#define D 10e-7

double imax(double x1[], double x2[], int N); 

int main() {

	FILE *fp;
	int N;

	
/* read the matrix from file */	
	fp =  fopen("06matrix", "r");
	if (fp == NULL) {
		fprintf(stderr, "Error while opening the file.\n");
		return 1;
	}
	fscanf(fp, "%d", &N);

	double A[N][N], B[N][N];   //  coefficient matrix
	double y[N], g[N];
	double x2[N], x1[N];
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			fscanf(fp, "%lf", &A[i][j]);
		}
		fscanf(fp, "%lf", &y[i]);
	}
	fclose(fp);

/* Gauss-seidel method */
	/* calculate Jacobi Matrix B */
	for (int i=0; i<N; i++) {
		g[i] = y[i]/A[i][i];
		for (int j=0; j<N; j++) {
			if(i==j) B[i][j] = 0;
			else {
				B[i][j] = -A[i][j]/A[i][i];
			}
		}
	}
	
	double bestw;
	int min = 10000000;
	for (int k=1; k<100; k++) {
		int step = 0;
		double w = k/50.0;
		for (int i=0; i<N; i++) {
			x2[i] = 0;
		}
		/* calculate x_i*/
		do{
			for (int i=0; i<N; i++) {
				x1[i] = x2[i];
				double s = g[i];
				for (int j=0; j<N; j++) {
					s += B[i][j]*x2[j];
				}
				x2[i] = (1-w)*x1[i]+w*s;
			}	
			step ++;
		}  while (imax(x1,x2,N)>D); 

		if (step<min) {
			min = step;
			bestw = w;
		}

		/* print the root */	
		printf("w: %lf, iteration: %d step(s)!\n", w, step);
		for (int i=0; i<N; i++) {
			printf("%0.7lf\n", x2[i]);
		}
	}

	fprintf(stderr, "best w: %lf, minum steps: %d\n", bestw, min);
	return 0;
}


double imax(double x1[], double x2[], int N) {
	double max = 0;
	for (int i=0; i<N; i++) {
		if ((fabs(x1[i]-x2[i])) > max) {
			max = fabs(x1[i]-x2[i]);
		}
	}
	return max;

}


