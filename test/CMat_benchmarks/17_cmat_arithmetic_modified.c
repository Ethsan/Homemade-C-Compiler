int main()
{
	matrix A[2][3];
	matrix B[2][3];
	matrix C[2][3];
	A[0][0] = 1.0;
	A[0][1] = 1.0;
	A[0][2] = 1.0;
	A[1][0] = 2.0;
	A[1][1] = 2.0;
	A[1][2] = 2.0;
	B[0][0] = 1.0;
	B[0][1] = 2.0;
	B[0][2] = 3.0;
	B[1][0] = 1.0;
	B[1][1] = 2.0;
	B[1][2] = 3.0;
	C = A + B - A;
	printmat(C);
}