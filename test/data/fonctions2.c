int printf(int *string);
int printint(int i);
int printfloat(float f);

int add(int a, int b, int c, int d, int e, int f, int g, int h)
{
	return a + b + c + d + e + f + g + h;
}

float add_f(float a, float b, float c, float d, float e, float f, float g, float h)
{
	return a + b + c + d + e + f + g + h;
}

int main()
{
	int c;
	float f;
	c = add(1, 1, 1, 1, 1, 1, 1, 1);
	printf("c = ");
	printint(c);
	printf("\n");

	f = add_f(1., 1., 1., 1., 1., 1., 1., 1.);
	printf("f = ");
	printfloat(f);
	printf("\n");
}
