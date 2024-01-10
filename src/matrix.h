typedef struct matrix {
	int rows;
	int cols;
	float *data;
} matrix;

matrix make_matrix(int rows, int cols);

matrix mat_transpose(matrix m);

matrix mat_sum(matrix m1, matrix m2);

matrix mat_sub(matrix m1, matrix m2);

matrix mat_mul(matrix m1, matrix m2);

matrix mat_div(matrix m1, matrix m2);

matrix mat_mul_scalar(matrix m, float s);

matrix mat_div_scalar(matrix m, float s);

matrix mat_sum_scalar(matrix m, float s);
matrix mat_sub_scalar(matrix m, float s);

// ex m++
matrix mat_plus(matrix m);

// ex m--
matrix mat_minus(matrix m);
matrix mat_oppose(matrix m);

matrix mat_extract(matrix m, int row_start, int row_end, int col_start, int col_end);
