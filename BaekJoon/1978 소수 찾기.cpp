#include <iostream>

using namespace std;

int isPrime(int n)
{
	int i;
	if (n == 1) return 0;
	for (i = 2; i*i <= n; i++)
		if (n%i == 0) return 0;
	return 1;
}

int main()
{
	int ans = 0, N;
	cin >> N;
	while (N--)
	{
		int input;
		cin >> input;
		ans += isPrime(input);
	}
	cout << ans << endl;


	return 0;
}