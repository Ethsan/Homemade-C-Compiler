int printf(int *string);
int printint(int i);
int printfloat(float f);

int multiply(int a, int b)
{
	int c;
	c = a * b;
	return c;
}

float multiply_f(float a, float b)
{
	float c;
	c = a * b;
	return c;
}
int main()
{
	int a, b, c;
	float d, e, f;
        a = 4;
        b = 5;
        c= multiply(a,b);
        printf("c = ");
        printint(c);
        printf("\n");

        d = 4.3;
        e = 5.2;
        f = multiply_f(d,e);
        printf("f = ");
        printfloat(f);
        printf("\n");
}
