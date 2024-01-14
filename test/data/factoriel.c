int factoriel(int n) {
        if (n == 0) {
                return 1;
        } else {
                return n * factoriel(n - 1);
        }
}
int main() {
        int n, result;
        n = 4;
        result = factoriel(n);
        printf("factoriel ");
        printint(n);
        printf(" = ");
        printint(result);
        printf("\n");

}

