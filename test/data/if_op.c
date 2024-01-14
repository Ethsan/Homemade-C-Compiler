int printint(int num);
int main()
{
	int a;
	int b;
	int c;

	a = 1;
	b = 1;
	if (a && b) {
		c = 1;
	} else {
		c = 0;
	}
	printint(c);

	b = 0;
	if (a && b) {
		c = 0;
	} else {
		c = 1;
	}
	printint(c);

	b = 1;
	if (a || b) {
		c = 1;
	} else {
		c = 0;
	}
        printint(c);
        b=0;
	if (a || b) {
		c = 1;
	} else {
		c = 0;
	}
	printint(c);
        a=0;
        if(a || b){
                c = 0;
        } else {
                c = 1;
        }
        printint(c);
}
