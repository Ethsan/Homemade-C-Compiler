int main(){
        int n;
        float m;
        int a[10][5][3];
        float b[8][5][6];
        n = 4;
        a[1][2][2] = n;
        a[2][3][1] = 5;
        a[3][1][2] = a[1][2][2] + a[2][3][1];
        printf("a = ");
        printint(a[3][1][2]);
        printf("\n");

        m = 4.3;
        b[1][2][2] = m;
        b[2][3][1] = 5.2;
        b[3][1][2] = b[1][2][2] + b[2][3][1];
        printf("b = ");
        printfloat(b[3][1][2]);
        printf("\n");

}
