#include <stdio.h>
#include <math.h>

#define D 10e-7
double imax(double x1[], double x2[], int N) {
	double max = 0;
	for (int i=0; i<N; i++) {
		if ((fabs(x1[i]-x2[i])) > max) {
			max = fabs(x1[i]-x2[i]);
		}
	}
	return max;

}

int main() {

	FILE *fp;
	int N, step=0;      // N = Dimension of coefficient matrix

	
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
		x2[i] = 0;
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

	/* calculate x_i*/
	do{
		for (int i=0; i<N; i++) {
			x1[i] = x2[i];
			double s = g[i];
			for (int j=0; j<N; j++) {
				s += B[i][j]*x2[j];
			}
			x2[i] = s;
		}	
		step ++;
	}  while (imax(x1,x2,N)>D); 
	
	/* print the root */	
	printf("Iteration %d step(s)!\n", step);
	for (int i=0; i<N; i++) {
		printf("%0.7lf\n", x2[i]);
	}

	return 0;
}



