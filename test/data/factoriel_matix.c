int factoriel(matrix result[2][2],matrix m[2][2]) {
        if (n == 0) {
                return 1;
        } else {
                return n * factoriel(n - 1);
        }
}
int main() {
        matrix m[2][2];
        matrix result[2][2];
        result = factoriel(n);
        printf("factoriel ");
        printint(n);
        printf(" = ");
        printint(result);
        printf("\n");

}
