//#include <iostream>
//using namespace std;
//int dpTable[1010] = { 0,1,1 };
//
//int main() {
//	int n;
//	cin >> n;
//	n++;
//	for (int i = 3; i <= n; i++)
//		dpTable[i] = dpTable[i - 1]%10007 + dpTable[i - 2]%10007;
//
//
//	cout << dpTable[n]%10007;
//
//	return 0;
//}