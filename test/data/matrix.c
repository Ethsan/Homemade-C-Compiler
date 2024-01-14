int main()
{
	matrix a[2][2];

	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;

	printf("a = \n");
	print_mat(a);
	printf("a + a = \n");
	print_mat(a + a);
	printf("a - a = \n");
	print_mat(a - a);
	printf("a * a = \n");
	print_mat(a * a);
}
