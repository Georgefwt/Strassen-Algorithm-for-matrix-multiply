#ifndef MAXSIZE
#define MAXSIZE 16//change if necessary!
#endif // !MAXSIZE

typedef struct matrix {
	int (*m)[MAXSIZE+1][MAXSIZE+1];
	int ltrow, ltcol;
	int row;
	int col;
}matrix;

//typedef struct submatrix {
//	matrix *mat;
//	int row, col;
//	int ltrow, ltcol;
//}submatrix;

void newmatrix(matrix *mat,int *m,int row,int col);
void regu_multi(matrix *a, matrix *b, matrix *returnmatrix);
void strassen_mult(matrix *a, matrix *b, matrix *returnmatrix);
void strassen_multA(matrix *a, matrix *b, matrix *returnmatrix);
void strassen_multB(matrix *a, matrix *b, matrix *returnmatrix);