#pragma warning(disable:4996)
#include<stdio.h>
#include<time.h>
#include"matrix.h"
#define CLOCKS_PER_SEC ((clock_t)1000)

int main() {
	clock_t start, finish;
	double duration;
	FILE *pa, *pb;
	pa = fopen("matrixA2048.txt", "r");
	pb = fopen("matrixI2048.txt", "r");

	int ma[MAXSIZE + 1][MAXSIZE + 1];
	int mb[MAXSIZE + 1][MAXSIZE + 1];
	int mc[MAXSIZE + 1][MAXSIZE + 1];

	for (int i = 0; i < MAXSIZE; i++) {
		for (int j = 0; j < MAXSIZE; j++) {
			fscanf(pa, "%d", &ma[i+1][j+1]);
			fscanf(pb, "%d", &mb[i+1][j+1]);
		}
	}

	matrix a, b, c;

	newmatrix(&a, ma,MAXSIZE,MAXSIZE);
	newmatrix(&b, mb,MAXSIZE,MAXSIZE);
	newmatrix(&c, mc, MAXSIZE, MAXSIZE);
	start = clock();
	regu_multi(&a, &b, &c);
	finish = clock();
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			printf("%d ", (*c.m)[i][j]);
		}
		printf("\n");
	}
	duration = (double)(finish - start);
	printf("%f ms\n", duration);
	return 0;
}