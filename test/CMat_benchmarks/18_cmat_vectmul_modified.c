int main()
{
	matrix A[3];
	matrix B[3];
	matrix C[1];
	A[0] = 1.0;
	A[1] = 2.0;
	A[2] = 3.0;
	B[0] = 4.0;
	B[1] = 5.0;
	B[2] = 6.0;
	C = A * B;
	printmat(C);
}
