int printint(int num);
int printf(char *string);
int main()
{
	int a;
	int b;

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
        b=0;
	if (a || b) {
		printf("ok\n");
	} else {
		printf("error\n");
	}
        a=0;
        if(a || b){
                printf("error\n");
        } else {
                printf("ok\n");
        }
}
