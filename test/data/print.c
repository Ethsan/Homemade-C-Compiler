int printf(int *string);
int printint(int i);
int printfloat(float f);

int main()
{
	int i;
	float f;
	i = 10;
	f = 10.0;
	printf("Hello World!\n");
	printint(i);
        printf("\n");
	printfloat(f);
        printf("\n");
	return 0;
}