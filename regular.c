#include<stdio.h>
#include"matrix.h"
//#include"matrix.cpp"

void regu_multi(matrix *a, matrix *b, matrix *returnmatrix) {
	if (a->col != b->row) {
		printf("wrong input!");
		return;
	}
	//init
	for (int i = 1; i <= a->row; i++) {
		for (int j = 1; j <= b->col; j++) {
			(*returnmatrix->m)[i][j] = 0;
		}
	}
	returnmatrix->row = a->row;
	returnmatrix->col = b->col;
	for (int i = 1; i <= a->row; i++) {
		for (int j = 1; j <= b->col; j++) {
			for (int k = 1; k <= a->col; k++) {
				(*returnmatrix->m)[i][j] += (*a->m)[i][k] * (*b->m)[k][j];
			}
		}
	}
}
