int f(int x) {
  printint(x);
  return x;
}

float g(float y) {
  printfloat(y);
  return y;
}

int main() {
  int a; 
  float b; 
  b = f(42.42);
  a = g(42);
  printint(a);
  printfloat(b);
  return 0;
}
