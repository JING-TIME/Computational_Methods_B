#include<stdio.h>
#include<math.h>

#define NUM 1E9


int main() {
	double x[7] = {0.0, 0.5, 1.0, sqrt(2), 10.0, 100.0, 300.0};

//	printf("Please input x: ");
//	scanf("%lf", &x);

	/*sum of series*/
	for(int i=0; i<7; i++) {
		double sum = 0;
		for(int k=1; k<NUM; k++) {
			sum = sum + 1/(k*(k+x[i]));
		}	
		printf("x = %f, y = %.15f\n", x[i], sum);
	}
	return 0;
}
