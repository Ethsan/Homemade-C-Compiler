int printf(int *string);
int printint(int i);
int printfloat(float f);

int main() {
    int i;
    float f;
    i = 10;
    f = 10.0;
    printf("Hello World!\n");
    printf("i = %d\n", i);
    printf("f = %f\n", f);
    return 0;
}