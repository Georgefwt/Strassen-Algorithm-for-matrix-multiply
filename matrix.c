#include "matrix.h"

void newmatrix(matrix *mat, int *m, int row, int col)
{
	mat->row = row;
	mat->col = col;
	mat->ltcol = 1;
	mat->ltrow = 1;
	mat->m = m;
	/*for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mat->m[i+1][j+1] = m[i*col + j];
		}
	}*/
}


