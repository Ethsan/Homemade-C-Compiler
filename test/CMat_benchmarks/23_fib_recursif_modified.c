int Fibonacci(int n)
{
	if (n < 2) {
		return n;
	}
	return Fibonacci(n - 2) + Fibonacci(n - 1);
}

int main() {

	int valeur; 
        valeur = 10;
	
	print(Fibonacci(valeur));
	
	return 0;

}
