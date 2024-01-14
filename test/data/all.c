int factoriel(int n)
{
	if (n == 0) {
		return 1;
	} else {
		return n * factoriel(n - 1);
	}
}
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
	int i, j, k, n, a, b, c,result;
	float f, g, h, m, e, d;
	int z[10][5][3];
	float y[8][5][6];

	printf("test print\n");
	i = 10;
	f = 10.0;
	printf("Hello World!\n");
	printint(i);
	printf("\n");
	printfloat(f);
	printf("\n");

	printf("test add\n");
	i = 10;
	j = 5;
	k = i + j;
	printf("10+5 = ");
	printint(k);
	printf("\n");

	f = 10.0;
	g = 5;
	h = f + g;
	printf("10.0+5 = ");
	printfloat(h);
	printf("\n");

	printf("test tableau\n");
	n = 4;
	z[1][2][2] = n;
	z[2][3][1] = 5;
	z[3][1][2] = z[1][2][2] + z[2][3][1];
	printf("tableau z[3][1][2] = ");
	printint(z[3][1][2]);
	printf("\n");

	m = 4.3;
	y[1][2][2] = m;
	y[2][3][1] = 5.2;
	y[3][1][2] = y[1][2][2] + y[2][3][1];
	printf("tableau y[3][1][2] = ");
	printfloat(y[3][1][2]);
	printf("\n");

	printf("test for while\n");
	a = 0;
	for (i = 0; i < 80; i++) {
		a++;
	}
	printf("for i<80 a = ");
	printint(a);
	printf("\n");
	a = 0;
	i = 0;

	while (i < 50) {
		a++;
		i++;
	}
	printf("while i<50 a = ");
	printint(a);
	printf("\n");

	printf("test opération sur les entiers\n");
	a = 2;
	b = 9;
	printf("a : ");
	printint(a);
	printf("\n");
	printf("b : ");
	printint(b);
	printf("\n");

	c = b - a;
	printf("b - a : ");
	printint(c);
	printf("\n");
	c = b * a;
	printf("b * a : ");
	printint(c);
	printf("\n");
	c = b / a;
	printf("b / a : ");
	printint(c);
	printf("\n");

	c = b % a;
	printf("b % a : ");
	printint(c);
	printf("\n");

	c = -a;
	printf("-a : ");
	printint(c);
	printf("\n");

	printf("test opération sur les flottants\n");
	f = 7.;
	g = 8.;
	printf("f : ");
	printfloat(f);
	printf("\n");
	printf("g : ");
	printfloat(g);
	printf("\n");

	h = g - f;
	printf("g - f : ");
	printfloat(h);
	printf("\n");
	h = g * f;
	printf("g * f: ");
	printfloat(h);
	printf("\n");
	h = g / f;
	printf("g / f: ");
	printfloat(h);
	printf("\n");

	h = -f;
	printf("-f: ");
	printfloat(h);
	printf("\n");

	printf("test if else opération logique\n ");
	a = 1;
	b = 1;
	if (a && b) {
		printf("ok\n");
	} else {
		printf("error\n");
	}

	b = 0;
	if (a && b) {
		printf("error\n");
	} else {
		printf("ok\n");
	}

	b = 1;
	if (a || b) {
		printf("ok\n");
	} else {
		printf("error\n");
	}
	b = 0;
	if (a || b) {
		printf("ok\n");
	} else {
		printf("error\n");
	}
	a = 0;
	if (a || b) {
		printf("error\n");
	} else {
		printf("ok\n");
	}

	printf("test if else opérateur relationnel\n ");
	a = 1;
	b = 2;
	if (a < b) {
		printf("ok\n");
	} else {
		printf("error\n");
	}

	if (a > b) {
		printf("error\n");
	} else {
		printf("ok\n");
	}

	if (a == b) {
		printf("error\n");
	} else {
		printf("ok\n");
	}
	b = 1;
	if (a == b) {
		printf("ok\n");
	} else {
		printf("error\n");
	}
	if (a != b) {
		printf("error\n");
	} else {
		printf("ok\n");
	}

	if (a <= b) {
		printf("ok\n");
	} else {
		printf("error\n");
	}
	if (a >= b) {
		printf("ok\n");
	} else {
		printf("error\n");
	}

	e = 1.;
	f = 2.;
	if (e < f) {
		printf("ok\n");
	} else {
		printf("error\n");
	}

	if (e > f) {
		printf("error\n");
	} else {
		printf("ok\n");
	}

	if (e == f) {
		printf("error\n");
	} else {
		printf("ok\n");
	}
	f = 1.;
	if (e == f) {
		printf("ok\n");
	} else {
		printf("error\n");
	}
	if (e != f) {
		printf("error\n");
	} else {
		printf("ok\n");
	}

	if (e <= f) {
		printf("ok\n");
	} else {
		printf("error\n");
	}
	if (e >= f) {
		printf("ok\n");
	} else {
		printf("error\n");
	}

        printf("test fonction multiply entier et float\n");
        a = 4;
        b = 5;
        c= multiply(a,b);
        printf("4*5 = ");
        printint(c);
        printf("\n");

        d = 4.3;
        e = 5.2;
        f = multiply_f(d,e);
        printf("4.3 * 5.2 = ");
        printfloat(f);
        printf("\n");

        printf("test fonction avec 8 arguments\n");
        c = add(1, 1, 1, 1, 1, 1, 1, 1);
	printf("c = ");
	printint(c);
	printf("\n");

	f = add_f(1., 1., 1., 1., 1., 1., 1., 1.);
	printf("f = ");
	printfloat(f);
	printf("\n");

	printf("test récurcivité (4!)\n");

	n = 4;
	result = factoriel(n);
	printf("factoriel ");
	printint(n);
	printf(" = ");
	printint(result);
	printf("\n");



	return 0;

}
