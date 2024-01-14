void mat_transpose(int r, int c, float *out, float *in);

void mat_sum(int r, int c, float *out, float *in1, float *in2);

void mat_sub(int r, int c, float *out, float *int1, float *in2);

void mat_mul(int r1, int c1, int r2, int c2, float *out, float *in1, float *in2);

void mat_mul_scalar(int r, int c, float scalar, float *out, float *in);

void mat_div_scalar(int r, int c, float scalar, float *out, float *in);

void mat_sum_scalar(int r, int c, float scalar, float *out, float *in);

void mat_sub_scalar(int r, int c, float scalar, float *out, float *in);

void mat_copy_row(int r_in, int c_in, int r_out, int c_out, int r_start, int r_end, int r_off, float *out, float *in);

void mat_copy_col(int r_in, int c_in, int r_out, int c_out, int c_start, int c_end, int c_off, float *out, float *in);

void mat_print(int r, int c, float *in);
