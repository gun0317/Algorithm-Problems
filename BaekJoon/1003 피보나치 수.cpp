//#include <iostream>
//
//using namespace std;
//
//long int fibTable[100];
//
//long int fib(int n)
//{
//	if (n == 0)
//		return 0;
//	if (!fibTable[n])
//		fibTable[n] = fib(n-1) + fib(n - 2);
//	return fibTable[n];
//}
//int main()
//{
//	fibTable[0] = 0;
//	fibTable[1] = 1;
//	fibTable[2] = 1;
//	int T, N;
//	cin >> T;
//	while (T--)
//	{
//		cin >> N;
//		if (N == 0)
//			cout << 1 << " " << 0 << endl;
//		else
//			cout << fib(N-1) << " " <<fib(N)  << endl;
//	}
//
//	return 0;
//}