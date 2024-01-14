

void mat_transpose(int r, int c, float *out, float *in)
{
	int i, j;
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) {
			out[j * c + i] = in[i * c + j];
		}
	}
}

void mat_sum(int r, int c, float *out, float *in1, float *in2)
{
	int i, j;
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) {
			out[i * c + j] = in1[i * c + j] + in2[i * c + j];
		}
	}
}

void mat_sub(int r, int c, float *out, float *in1, float *in2)
{
	int i, j;
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) {
			out[i * c + j] = in1[i * c + j] - in2[i * c + j];
		}
	}
}

void mat_mul(int r1, int c1, int r2, int c2, float *out, float *in1, float *in2)
{
	int i, j, k;
	for (i = 0; i < r1; ++i) {
		for (j = 0; j < c2; ++j) {
			for (k = 0; k < c1; ++k) {
				out[i * c2 + j] += in1[i * c1 + k] * in2[k * c2 + j];
			}
		}
	}
}

void mat_div(int r1, int c1, int r2, int c2, float *out, float *in1, float *in2)
{
	int i, j, k;
	for (i = 0; i < r1; ++i) {
		for (j = 0; j < c2; ++j) {
			out[i * c2 + j] = 0;
			for (k = 0; k < c1; ++k) {
				out[i * c2 + j] += in1[i * c1 + k] * in2[k * c2 + j];
			}
		}
	}
}

void mat_mul_scalar(int r, int c, float s, float *out, float *in)
{
	int i, j;
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) {
			out[i * c + j] = in[i * c + j] * s;
		}
	}
}

void mat_div_scalar(int r, int c, float s, float *out, float *in)
{
	int i, j;
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) {
			out[i * c + j] = in[i * c + j] / s;
		}
	}
}

void mat_sum_scalar(int r, int c, float s, float *out, float *in)
{
	int i, j;
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) {
			out[i * c + j] = in[i * c + j] + s;
		}
	}
}

void mat_sub_scalar(int r, int c, float s, float *out, float *in)
{
	int i, j;
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) {
			out[i * c + j] = in[i * c + j] - s;
		}
	}
}

void mat_copy(int r, int c, float *out, float *in)
{
	int i, j;
	for (i = 0 ; i < r; ++i) {
		for (j = 0; j < c; ++j){
			out[i * c + j] = in[i * c + j];
		}
	}
}

void mat_copy_row(int r_in, int c_in, int r_out, int c_out, int r_start, int r_end, int c_off, float *out, float *in) {
	int i, j;
	for (i = r_start; i < r_end; ++i) {
		for (j = 0; j < c_in; ++j) {
			out[(i - r_start) * c_out + j + c_off] = in[i * c_in + j];
		}
	}
}

void mat_copy_col(int r_in, int c_in, int r_out, int c_out, int c_start, int c_end, int r_off, float *out, float *in) {
	int i, j;
	for (i = 0; i < r_in; ++i) {
		for (j = c_start; j < c_end; ++j) {
			out[i * c_out + j - c_start + r_off * c_out] = in[i * c_in + j];
		}
	}
}
int printf(int *string);
int printfloat(int i);

void mat_print(int r, int c, float *in)
{
	int i, j;
	printf("\n");
	for (i = 0 ; i < r; ++i) {
		for (j = 0; j < c; ++j){
			printfloat(in[i * c + j]);
			printf(" ");
		}
		printf("\n");
	}
}