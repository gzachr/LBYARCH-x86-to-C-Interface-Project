#include <stdio.h>
#include <stdlib.h>

extern void saxpy_x86_64(int, double*, double*, double*);

int main() {
	const int N = 1 << 15; // 2^n change the second operand depending on N
	const size_t ARRAY_SIZE = N * sizeof(double); 

	double *vectorX, *vectorY, *vectorZ;
	vectorX = (double*)malloc(ARRAY_SIZE);
	vectorY = (double*)malloc(ARRAY_SIZE);
	vectorZ = (double*)malloc(ARRAY_SIZE);

	if (vectorX == NULL || vectorY == NULL || vectorZ == NULL) {
		printf("Memory Allocation Failed");
		return 1;
	}

	int counter;
	double i, j;
	for (counter = 0, i = 1.0, j = 11.0; counter < N; counter++, i++, j++) {
		vectorX[counter] = i;
		vectorY[counter] = j;
	}

	// call x86-64 kernel
	saxpy_x86_64(N, vectorX, vectorY, vectorZ);

	for (counter = 0; counter < 10; counter++) {
		printf("Output %d: %lf\n", counter + 1, vectorZ[counter]);
	}

	return 0;
}