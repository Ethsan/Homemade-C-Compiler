int main() {
  int a[10];
  int i;
  a[0] = 1;

  for(i = 1; i < 10; i = i + 1) {
    a[i] = a[i-1] * 2;
    printint(a[i]);
  }
}
