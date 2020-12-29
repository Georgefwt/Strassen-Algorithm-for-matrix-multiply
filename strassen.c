#include<stdio.h>
#include"matrix.h"

void copymat(matrix *source,matrix *target,int ltrow,int ltcol,int row,int col) {//这里row和col指复制矩阵的大小
	target->row = row;
	target->col = col;
	//target->ltcol =source->ltcol+ltcol;
	//target->ltrow =source->ltrow+ltrow;
	target->ltcol = ltcol;
	target->ltrow = ltrow;
	target->m = source->m;
}

void addmat(matrix *a, matrix *b, matrix *returnmatrix, int rlr, int rlc) {

	for (int i = 1; i <= a->row; i++) {
		for (int j = 1; j <= b->col; j++) {
			(*returnmatrix->m)[i + rlr - 1][j + rlc - 1] = (*a->m)[i + a->ltrow - 1][j + a->ltcol - 1] + (*b->m)[i + b->ltrow - 1][j + b->ltcol - 1];
		}
	}
}
void submat(matrix *a, matrix *b, matrix *returnmatrix, int rlr, int rlc) {

	for (int i = 1; i <= a->row; i++) {
		for (int j = 1; j <= b->col; j++) {
			(*returnmatrix->m)[i + rlr - 1][j + rlc - 1] = (*a->m)[i + a->ltrow - 1][j + a->ltcol - 1] - (*b->m)[i + b->ltrow - 1][j + b->ltcol - 1];
		}
	}
}

//when a amd returnmat actually the same
void addmat2(matrix *a, matrix *b, matrix *returnmatrix, int rlr, int rlc) {
	for (int i = 1; i <= a->row/2; i++) {
		for (int j = 1; j <= b->col; j++) {
			(*returnmatrix->m)[i + rlr - 1][j + rlc - 1] = (*a->m)[i + rlr - 1][j + rlc - 1] + (*b->m)[i + b->ltrow - 1][j + b->ltcol - 1];
		}
	}
}
void submat2(matrix *a, matrix *b, matrix *returnmatrix, int rlr, int rlc) {
	for (int i = 1; i <= a->row/2; i++) {
		for (int j = 1; j <= b->col; j++) {
			(*returnmatrix->m)[i + rlr - 1][j + rlc - 1] = (*a->m)[i + rlr - 1][j + rlc - 1] - (*b->m)[i + b->ltrow - 1][j + b->ltcol - 1];
		}
	}
}

void addmatpro(matrix *a, matrix *b, matrix *returnmatrix,int rlr,int rlc) {
	returnmatrix->col = a->col;
	returnmatrix->row = a->row;
	returnmatrix->ltrow = rlr;
	returnmatrix->ltcol = rlc;
	for (int i = 1; i <= a->row; i++) {
		for (int j = 1; j <= b->col; j++) {
			(*returnmatrix->m)[i+rlr-1][j+rlc-1] = (*a->m)[i+a->ltrow -1][j+a->ltcol-1] + (*b->m)[i+b->ltrow-1][j+b->ltcol-1];
		}
	}
}
void submatpro(matrix *a, matrix *b, matrix *returnmatrix, int rlr, int rlc) {
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


void strassenmult(matrix *a, matrix *b, matrix *returnmatrix) {
	returnmatrix->row = a->row;
	returnmatrix->col = b->col;
	if (a->row==1 || a->col==1){
		(*returnmatrix->m)[returnmatrix->ltrow][returnmatrix->ltcol] = (*a->m)[a->ltrow][a->ltcol] * (*b->m)[b->ltrow][b->ltcol];
		return;
	}
	matrix A11, A12, A21, A22, B11, B12, B21, B22;
	copymat(a, &A11, a->ltrow, a->ltcol, a->row / 2, a->col / 2);
	copymat(a, &A12, a->ltrow, a->col/2+ a->ltcol, a->row / 2, a->col / 2);
	copymat(a, &A21, a->row/2+ a->ltrow, a->ltcol, a->row / 2, a->col / 2);
	copymat(a, &A22, a->row/2+ a->ltrow, a->col/2+ a->ltcol, a->row / 2, a->col / 2);
	copymat(b, &B11, b->ltrow, b->ltcol, b->row / 2, b->col / 2);
	copymat(b, &B12, b->ltrow, b->col/2+ b->ltcol, b->row / 2, b->col / 2);
	copymat(b, &B21, b->row/2+ b->ltrow, b->ltcol, b->row / 2, b->col / 2);
	copymat(b, &B22, b->row/2+ b->ltrow, b->col/2+ b->ltcol, b->row / 2, b->col / 2);
	//matrix S14, S58, S90;
	int s14m[MAXSIZE + 1][MAXSIZE + 1], s58m[MAXSIZE + 1][MAXSIZE + 1], s90m[MAXSIZE + 1][MAXSIZE + 1];
	matrix S1, S2, S3, S4, S5, S6, S7, S8, S9, S10;
	S1.m = &s14m;S2.m = &s14m;S3.m = &s14m;S4.m = &s14m;
	S5.m = &s58m;S6.m = &s58m;S7.m = &s58m;S8.m = &s58m;
	S9.m = &s90m;S10.m = &s90m;

	submatpro(&B12, &B22, &S1,1,1);
	addmatpro(&A11, &A12, &S2,1,a->col/2+1);
	addmatpro(&A21, &A22, &S3,a->row/2+1,1);
	submatpro(&B21, &B11, &S4,a->row / 2 + 1, a->col / 2 + 1);
	addmatpro(&A11, &A22, &S5,1,1);
	addmatpro(&B11, &B22, &S6, 1, a->col / 2 + 1);
	submatpro(&A12, &A22, &S7,a->row / 2 + 1, 1);
	addmatpro(&B21, &B22, &S8, a->row / 2 + 1, a->col / 2 + 1);
	submatpro(&A11, &A21, &S9, 1, 1);
	addmatpro(&B11, &B12, &S10, 1, a->col / 2 + 1);
	matrix P1, P2, P3, P4, P5, P6, P7;
	P1.ltrow = S1.ltrow; P1.ltcol = S1.ltcol; P1.m = &s14m;
	P2.ltrow = S2.ltrow; P2.ltcol = S2.ltcol; P2.m = &s14m;
	P3.ltrow = S3.ltrow; P3.ltcol = S3.ltcol; P3.m = &s14m;
	P4.ltrow = S4.ltrow; P4.ltcol = S4.ltcol; P4.m = &s14m;
	P5.ltrow = S5.ltrow; P5.ltcol = S5.ltcol; P5.m = &s58m;
	P6.ltrow = S7.ltrow; P6.ltcol = S7.ltcol; P6.m = &s58m;
	P7.ltrow = S9.ltrow; P7.ltcol = S9.ltcol; P7.m = &s90m;
	strassenmult(&A11, &S1, &P1);
	strassenmult(&S2, &B22, &P2);
	strassenmult(&S3, &B11, &P3);
	strassenmult(&A22, &S4, &P4);
	strassenmult(&S5, &S6, &P5);
	strassenmult(&S7, &S8, &P6);
	strassenmult(&S9, &S10, &P7);
	//matrix C11, C12, C21, C22;
	//C11.m = returnmatrix->m; C11.row = returnmatrix->row / 2; C11.col = returnmatrix->col / 2;
	//C11.ltrow = 1; C11.ltcol = 1;
	//C12.m = returnmatrix->m; C12.row = returnmatrix->row / 2; C12.col = returnmatrix->col / 2;
	//C12.ltrow = 1; C12.ltcol = returnmatrix->col / 2+1;
	//C21.m = returnmatrix->m; C21.row = returnmatrix->row / 2; C21.col = returnmatrix->col / 2;
	//C21.ltrow = returnmatrix->row / 2+1; C21.ltcol = 1;
	//C22.m = returnmatrix->m; C22.row = returnmatrix->row / 2; C22.col = returnmatrix->col / 2;
	//C22.ltrow = returnmatrix->row / 2+1; C22.ltcol = returnmatrix->col / 2+1;
	addmat(&P5, &P4, returnmatrix,returnmatrix->ltrow,returnmatrix->ltcol);
	submat2(returnmatrix, &P2,returnmatrix, returnmatrix->ltrow, returnmatrix->ltcol);
	addmat2(returnmatrix, &P6, returnmatrix, returnmatrix->ltrow, returnmatrix->ltcol);
	addmat(&P1, &P2, returnmatrix, returnmatrix->ltrow, returnmatrix->ltcol+returnmatrix->col/2);
	addmat(&P3, &P4, returnmatrix,returnmatrix->ltrow+returnmatrix->row/2,returnmatrix->ltcol);
	addmat(&P5, &P1, returnmatrix,returnmatrix->ltrow+returnmatrix->row/2,returnmatrix->ltcol+returnmatrix->col/2);
	submat2(returnmatrix, &P3, returnmatrix, returnmatrix->ltrow + returnmatrix->row / 2, returnmatrix->ltcol + returnmatrix->col / 2);
	submat2(returnmatrix, &P7, returnmatrix, returnmatrix->ltrow + returnmatrix->row / 2, returnmatrix->ltcol + returnmatrix->col / 2);

	//combinematrix(&C11, &C12, &C21, &C22, returnmatrix);
}


void strassen_mult(matrix *a, matrix *b, matrix *returnmatrix) {
	if (a->col != b->row) {
		printf("wrong input!");
		return;
	}
	//extendmatto2(a);
	//extendmatto2(b);
	strassenmult(a, b, returnmatrix);
	returnmatrix->row = a->row;
	returnmatrix->col = b->col;
}
