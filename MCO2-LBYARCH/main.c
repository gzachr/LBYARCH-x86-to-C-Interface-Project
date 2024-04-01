#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void saxpy_x86_64(int, float*, float*, float*, float);
extern void saxpy_c(int n, float a, float* x, float* y, float* z);

int main() {
	const int N = 1 << 20; // 2^n change the second operand depending on N
	const size_t ARRAY_SIZE = N * sizeof(double);
	const float A = 2.0;
	clock_t begin, end;
	double time_taken;
	double elapsed_time = 0;
	double avg_time;

	float* vectorX, * vectorY, * vectorZ1, *vectorZ2;
	vectorX = (float*)malloc(ARRAY_SIZE);
	vectorY = (float*)malloc(ARRAY_SIZE);
	vectorZ1 = (float*)malloc(ARRAY_SIZE);
	vectorZ2 = (float*)malloc(ARRAY_SIZE);

	if (vectorX == NULL || vectorY == NULL || vectorZ1 == NULL || vectorZ2 == NULL) {
		printf("Memory Allocation Failed");
		return 1;
	}

	// initialize vector X and Y
	int counter;
	float i, j;
	for (counter = 0, i = 1.0, j = 11.0; counter < N; counter++, i++, j++) {
		vectorX[counter] = i;
		vectorY[counter] = j;
	}

	// fill the cache so cache hit
	// saxpy_x86_64(N, vectorX, vectorY, vectorZ1, A);


	int loop = 30;

	// call x86-64 kernel
	for (int time_counter = 0; time_counter < loop; time_counter++) {
		begin = clock();
		saxpy_x86_64(N, vectorX, vectorY, vectorZ1, A);
		end = clock();
		time_taken = ((double)(end - begin)) * 1e3 / CLOCKS_PER_SEC;
		elapsed_time += time_taken;
	}

	avg_time = ((double)elapsed_time / loop);
	printf("BEGINNING PROGRAM WITH VECTOR SIZE = %d\n\n", N);

	printf("x86_64 Function:\n");
	for (counter = 0; counter < 10; counter++) {
		printf("\tOutput %d: %f\n", counter + 1, vectorZ1[counter]);
	}
	printf("\nx86_64 Function takes an average time of %lf milliseconds (30 runs made)\n\n", avg_time);

	// clear elapsed_time and avg_time
	elapsed_time = 0;
	avg_time = 0;

	// fill the cache so cache hit
	// saxpy_c(N, A, vectorX, vectorY, vectorZ2);

	for (int time_counter = 0; time_counter < loop; time_counter++) {
		begin = clock();
		saxpy_c(N, A, vectorX, vectorY, vectorZ2);
		end = clock();
		time_taken = ((double)(end - begin)) * 1e3 / CLOCKS_PER_SEC;
		elapsed_time += time_taken;
	}

	avg_time = ((double)elapsed_time / loop);


	printf("C Function:\n");
	for (counter = 0; counter < 10; counter++) {
		printf("\tOutput %d: %f\n", counter + 1, vectorZ2[counter]);
	}
	printf("\nC Function takes an average time of %lf milliseconds (30 runs made)", avg_time);

	// Determine Program Correctness
	int flag = 0;
	printf("\n\nAccuracy Verification:\n");
	for (counter = 0; counter < N; counter++) {
		if (vectorZ1[counter] != vectorZ2[counter]) {
			flag = 1;
			break;
		}
	}

	if (flag)
		printf("Unmatched value found.\n");
	else
		printf("Both x64 and C share the same results.\n");


	free(vectorX);
	free(vectorY);
	free(vectorZ1);
	free(vectorZ2);

	return 0;
}