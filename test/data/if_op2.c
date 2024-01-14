int printint(int num);
int printf(char *string);
int main()
{
	int a;
	int b;
	float e;
	float f;

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
	if (e <f) {
		printf("ok\n");
	} else {
		printf("error\n");
	}

	if (e >f) {
		printf("error\n");
	} else {
		printf("ok\n");
	}

	if (e ==f) {
		printf("error\n");
	} else {
		printf("ok\n");
	}
	b = 1.;
	if (e ==f) {
		printf("ok\n");
	} else {
		printf("error\n");
	}
	if (e !=f) {
		printf("error\n");
	} else {
		printf("ok\n");
	}

	if (e <=f) {
		printf("ok\n");
	} else {
		printf("error\n");
	}
	if (e >=f) {
		printf("ok\n");
	} else {
		printf("error\n");
	}

}