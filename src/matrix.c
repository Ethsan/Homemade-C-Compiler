
#include "matrix.h"

matrix make_matrix(int rows, int cols)
{
	matrix m;
	m.rows = rows;
	m.cols = cols;
	m.data = 0;
	return m;
}

matrix mat_transpose(matrix m)
{
	matrix t = make_matrix(m.cols, m.rows);
	int i, j;
	for (i = 0; i < m.rows; ++i) {
		for (j = 0; j < m.cols; ++j) {
			t.data[j * t.rows + i] = m.data[i * m.rows + j];
		}
	}
	return t;
}

matrix mat_sum(matrix m1, matrix m2)
{
	matrix sum = make_matrix(m1.rows, m1.cols);
	int i, j;
	for (i = 0; i < m1.rows; ++i) {
		for (j = 0; j < m1.cols; ++j) {
			sum.data[i * sum.rows + j] = m1.data[i * m1.rows + j] + m2.data[i * m2.rows + j];
		}
	}
	return sum;
}

matrix mat_sub(matrix m1, matrix m2)
{
	matrix sub = make_matrix(m1.rows, m1.cols);
	int i, j;
	for (i = 0; i < m1.rows; ++i) {
		for (j = 0; j < m1.cols; ++j) {
			sub.data[i * sub.rows + j] = m1.data[i * m1.rows + j] - m2.data[i * m2.rows + j];
		}
	}
	return sub;
}

matrix mat_mul(matrix m1, matrix m2)
{
	if (m1.cols != m2.rows) {
		return make_matrix(0, 0);
	}
	matrix mul = make_matrix(m1.rows, m2.cols);
	int i, j, k;
	for (i = 0; i < m1.rows; ++i) {
		for (j = 0; j < m2.cols; ++j) {
			for (k = 0; k < m1.cols; ++k) {
				mul.data[i * mul.rows + j] += m1.data[i * m1.rows + k] * m2.data[k * m2.rows + j];
			}
		}
	}
	return mul;
}

matrix mat_div(matrix m1, matrix m2)
{
	matrix div = make_matrix(m1.rows, m1.cols);
	int i, j;
	for (i = 0; i < m1.rows; ++i) {
		for (j = 0; j < m1.cols; ++j) {
			div.data[i * div.rows + j] = m1.data[i * m1.rows + j] / m2.data[i * m2.rows + j];
		}
	}
	return div;
}

matrix mat_mul_scalar(matrix m, float s)
{
	matrix mul = make_matrix(m.rows, m.cols);
	int i, j;
	for (i = 0; i < m.rows; ++i) {
		for (j = 0; j < m.cols; ++j) {
			mul.data[i * mul.rows + j] = m.data[i * m.rows + j] * s;
		}
	}
	return mul;
}

matrix mat_div_scalar(matrix m, float s)
{
	return mat_mul_scalar(m, 1.0 / s);
}

matrix mat_sum_scalar(matrix m, float s)
{
	matrix sum = make_matrix(m.rows, m.cols);
	int i, j;
	for (i = 0; i < m.rows; ++i) {
		for (j = 0; j < m.cols; ++j) {
			sum.data[i * sum.rows + j] = m.data[i * m.rows + j] + s;
		}
	}
	return sum;
}

matrix mat_sub_scalar(matrix m, float s)
{
	return mat_sum_scalar(m, -s);
}

// ex m++
matrix mat_plus(matrix m)
{
	return mat_sum_scalar(m, 1);
}

// ex m--
matrix mat_minus(matrix m)
{
	return mat_sub_scalar(m, 1);
}

matrix mat_oppose(matrix m)
{
	return mat_mul_scalar(m, -1);
}

matrix mat_extract(matrix m, int row_start, int row_end, int col_start, int col_end)
{
	// error gestion
	if (row_end > m.rows || col_end > m.cols || row_start < 0 || col_start < 0) {
		return make_matrix(0, 0);
	}
	if (row_start > row_end || col_start > col_end) {
		return make_matrix(0, 0);
	}

	matrix extract = make_matrix(row_end - row_start, col_end - col_start);
	int i, j;
	for (i = row_start; i < row_end; ++i) {
		for (j = col_start; j < col_end; ++j) {
			extract.data[(i - row_start) * extract.rows + (j - col_start)] = m.data[i * m.rows + j];
		}
	}
	return extract;
}
