#include <iostream>
using namespace std;
int zeros, ones;
int fib

int fibonacci(int n) {
	if (n == 0)
		return 0;
	if (!fibTable[n])
		fibTable[n] = fibTable[n - 1] + fibTable[n - 2];
	return fibTable[n];
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int ones;
		ones = fibonacci(N);
		int zeros = fibonacci(N + 1);
		cout << zeros << " " << ones << endl;
	}

	return 0;
}