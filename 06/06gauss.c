#include <stdio.h>
#include <math.h>


int main() {

	FILE *fp;
	int N;      // Dimension of coefficient matrix

	
/* read the matrix from file */
	
	fp =  fopen("06matrix", "r");

	if (fp == NULL) {
		fprintf(stderr, "Error while opening the file.\n");
		return 1;
	}

	fscanf(fp, "%d", &N);
//	printf("%d\n", N);

	double A[N][N+1];   //  coefficient matrix
	double x[N];        //  root of the equation
	for (int i=0; i<N; i++) {
		for (int j=0; j<N+1; j++) {
			fscanf(fp, "%lf", &A[i][j]);
		}
	}
	fclose(fp);

/* Gauss method */
	/* calculate upper triangular matrix */
	for (int i=0; i<N-1; i++) {
		/* find the max line */
		double max=0, temp;
		int s=0;
		for (int j=i; j<N; j++) {
			if (fabs(A[j][i]) > max) {
				max = fabs(A[j][i]);
				s = j;
			}
		}
		/* swap line i and s */
		if (s!=i) {		
			for (int j=i; j<N+1; j++) {
				temp = A[i][j];
				A[i][j] = A[s][j];
				A[s][j] = temp;
			}
		}
		/* multiply and add */
		for (int j=i+1; j<N; j++) {
			double mul = A[j][i];
			A[j][i] = 0;
			for (int k=i+1; k<N+1; k++) {
				A[j][k] = -A[i][k]*mul/A[i][i]+A[j][k];
			}
		}
	}
	/* calculate diagonal matrix */	
	for (int i=N-1; i>0; i--) {
		for (int j=0; j<i; j++) {
			A[j][N] -= A[i][N]*A[j][i]/A[i][i];
			A[j][i] = 0;
		}
	}
	/* calculate x_i*/
	for (int i=0; i<N; i++) {
		x[i] = A[i][N]/A[i][i];
		printf("x_%d = %0.15lf\n", i+1, x[i]);
	}

	/* print the matrix */	
//	for (int i=0; i<N; i++) {
//		for (int j=0; j<N+1; j++) {
//			printf("%0.2lf ", A[i][j]);
//		}
//		printf("\n");
//	}

	return 0;
}



