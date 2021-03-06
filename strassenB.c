#include<stdio.h>
#include"matrix.h"

void copymatB(matrix *source, matrix *target, int ltrow, int ltcol, int row, int col) {//����row��colָ���ƾ���Ĵ�С
	target->row = row;
	target->col = col;
	//target->ltcol =source->ltcol+ltcol;
	//target->ltrow =source->ltrow+ltrow;
	target->ltcol = ltcol;
	target->ltrow = ltrow;
	target->m = source->m;
}

void addmatB(matrix *a, matrix *b, matrix *returnmatrix, int rlr, int rlc) {

	for (int i = 1; i <= a->row; i++) {
		for (int j = 1; j <= b->col; j++) {
			(*returnmatrix->m)[i + rlr - 1][j + rlc - 1] = (*a->m)[i + a->ltrow - 1][j + a->ltcol - 1] + (*b->m)[i + b->ltrow - 1][j + b->ltcol - 1];
		}
	}
}
void submatB(matrix *a, matrix *b, matrix *returnmatrix, int rlr, int rlc) {

	for (int i = 1; i <= a->row; i++) {
		for (int j = 1; j <= b->col; j++) {
			(*returnmatrix->m)[i + rlr - 1][j + rlc - 1] = (*a->m)[i + a->ltrow - 1][j + a->ltcol - 1] - (*b->m)[i + b->ltrow - 1][j + b->ltcol - 1];
		}
	}
}

//when a amd returnmat actually the same
void addmat2B(matrix *a, matrix *b, matrix *returnmatrix, int rlr, int rlc) {
	for (int i = 1; i <= a->row / 2; i++) {
		for (int j = 1; j <= b->col; j++) {
			(*returnmatrix->m)[i + rlr - 1][j + rlc - 1] = (*a->m)[i + rlr - 1][j + rlc - 1] + (*b->m)[i + b->ltrow - 1][j + b->ltcol - 1];
		}
	}
}
void submat2B(matrix *a, matrix *b, matrix *returnmatrix, int rlr, int rlc) {
	for (int i = 1; i <= a->row / 2; i++) {
		for (int j = 1; j <= b->col; j++) {
			(*returnmatrix->m)[i + rlr - 1][j + rlc - 1] = (*a->m)[i + rlr - 1][j + rlc - 1] - (*b->m)[i + b->ltrow - 1][j + b->ltcol - 1];
		}
	}
}

void addmatproB(matrix *a, matrix *b, matrix *returnmatrix, int rlr, int rlc) {
	returnmatrix->col = a->col;
	returnmatrix->row = a->row;
	returnmatrix->ltrow = rlr;
	returnmatrix->ltcol = rlc;
	for (int i = 1; i <= a->row; i++) {
		for (int j = 1; j <= b->col; j++) {
			(*returnmatrix->m)[i + rlr - 1][j + rlc - 1] = (*a->m)[i + a->ltrow - 1][j + a->ltcol - 1] + (*b->m)[i + b->ltrow - 1][j + b->ltcol - 1];
		}
	}
}
void submatproB(matrix *a, matrix *b, matrix *returnmatrix, int rlr, int rlc) {
	returnmatrix->col = a->col;
	returnmatrix->row = a->row;
	returnmatrix->ltrow = rlr;
	returnmatrix->ltcol = rlc;
	for (int i = 1; i <= a->row; i++) {
		for (int j = 1; j <= b->col; j++) {
			(*returnmatrix->m)[i + rlr - 1][j + rlc - 1] = (*a->m)[i + a->ltrow - 1][j + a->ltcol - 1] - (*b->m)[i + b->ltrow - 1][j + b->ltcol - 1];
		}
	}
}


void strassenmultB(matrix *a, matrix *b, matrix *returnmatrix) {
	returnmatrix->row = a->row;
	returnmatrix->col = b->col;
	if (a->row <= 64 || a->col <= 64) {
		regu_multi(a, b, returnmatrix);
		//(*returnmatrix->m)[returnmatrix->ltrow][returnmatrix->ltcol] = (*a->m)[a->ltrow][a->ltcol] * (*b->m)[b->ltrow][b->ltcol];
		//return returnmatrix;
		return;
	}
	matrix A11, A12, A21, A22, B11, B12, B21, B22;
	copymatB(a, &A11, a->ltrow, a->ltcol, a->row / 2, a->col / 2);
	copymatB(a, &A12, a->ltrow, a->col / 2 + a->ltcol, a->row / 2, a->col / 2);
	copymatB(a, &A21, a->row / 2 + a->ltrow, a->ltcol, a->row / 2, a->col / 2);
	copymatB(a, &A22, a->row / 2 + a->ltrow, a->col / 2 + a->ltcol, a->row / 2, a->col / 2);
	copymatB(b, &B11, b->ltrow, b->ltcol, b->row / 2, b->col / 2);
	copymatB(b, &B12, b->ltrow, b->col / 2 + b->ltcol, b->row / 2, b->col / 2);
	copymatB(b, &B21, b->row / 2 + b->ltrow, b->ltcol, b->row / 2, b->col / 2);
	copymatB(b, &B22, b->row / 2 + b->ltrow, b->col / 2 + b->ltcol, b->row / 2, b->col / 2);
	//matrix S14, S58, S90;
	int s14m[MAXSIZE + 1][MAXSIZE + 1], s58m[MAXSIZE + 1][MAXSIZE + 1], s90m[MAXSIZE + 1][MAXSIZE + 1];
	matrix S1, S2, S3, S4, S5, S6, S7, S8, S9, S10;
	S1.m = &s14m; S2.m = &s14m; S3.m = &s14m; S4.m = &s14m;
	S5.m = &s58m; S6.m = &s58m; S7.m = &s58m; S8.m = &s58m;
	S9.m = &s90m; S10.m = &s90m;

	submatproB(&B12, &B22, &S1, 1, 1);
	addmatproB(&A11, &A12, &S2, 1, a->col / 2 + 1);
	addmatproB(&A21, &A22, &S3, a->row / 2 + 1, 1);
	submatproB(&B21, &B11, &S4, a->row / 2 + 1, a->col / 2 + 1);
	addmatproB(&A11, &A22, &S5, 1, 1);
	addmatproB(&B11, &B22, &S6, 1, a->col / 2 + 1);
	submatproB(&A12, &A22, &S7, a->row / 2 + 1, 1);
	addmatproB(&B21, &B22, &S8, a->row / 2 + 1, a->col / 2 + 1);
	submatproB(&A11, &A21, &S9, 1, 1);
	addmatproB(&B11, &B12, &S10, 1, a->col / 2 + 1);
	matrix P1, P2, P3, P4, P5, P6, P7;
	P1.ltrow = S1.ltrow; P1.ltcol = S1.ltcol; P1.m = &s14m;
	P2.ltrow = S2.ltrow; P2.ltcol = S2.ltcol; P2.m = &s14m;
	P3.ltrow = S3.ltrow; P3.ltcol = S3.ltcol; P3.m = &s14m;
	P4.ltrow = S4.ltrow; P4.ltcol = S4.ltcol; P4.m = &s14m;
	P5.ltrow = S5.ltrow; P5.ltcol = S5.ltcol; P5.m = &s58m;
	P6.ltrow = S7.ltrow; P6.ltcol = S7.ltcol; P6.m = &s58m;
	P7.ltrow = S9.ltrow; P7.ltcol = S9.ltcol; P7.m = &s90m;
	strassenmultB(&A11, &S1, &P1);
	strassenmultB(&S2, &B22, &P2);
	strassenmultB(&S3, &B11, &P3);
	strassenmultB(&A22, &S4, &P4);
	strassenmultB(&S5, &S6, &P5);
	strassenmultB(&S7, &S8, &P6);
	strassenmultB(&S9, &S10, &P7);
	addmatB(&P5, &P4, returnmatrix, returnmatrix->ltrow, returnmatrix->ltcol);
	submat2B(returnmatrix, &P2, returnmatrix, returnmatrix->ltrow, returnmatrix->ltcol);
	addmat2B(returnmatrix, &P6, returnmatrix, returnmatrix->ltrow, returnmatrix->ltcol);
	addmatB(&P1, &P2, returnmatrix, returnmatrix->ltrow, returnmatrix->ltcol + returnmatrix->col / 2);
	addmatB(&P3, &P4, returnmatrix, returnmatrix->ltrow + returnmatrix->row / 2, returnmatrix->ltcol);
	addmatB(&P5, &P1, returnmatrix, returnmatrix->ltrow + returnmatrix->row / 2, returnmatrix->ltcol + returnmatrix->col / 2);
	submat2B(returnmatrix, &P3, returnmatrix, returnmatrix->ltrow + returnmatrix->row / 2, returnmatrix->ltcol + returnmatrix->col / 2);
	submat2B(returnmatrix, &P7, returnmatrix, returnmatrix->ltrow + returnmatrix->row / 2, returnmatrix->ltcol + returnmatrix->col / 2);

	//combinematrix(&C11, &C12, &C21, &C22, returnmatrix);
}


void strassen_multB(matrix *a, matrix *b, matrix *returnmatrix) {
	if (a->col != b->row) {
		printf("wrong input!");
		return;
	}
	strassenmultB(a, b, returnmatrix);
	returnmatrix->row = a->row;
	returnmatrix->col = b->col;
}
