//#include <iostream>
//#include <algorithm>
//#define prev (i-1)%2
//#define next i%2
//using namespace std;
//int dp[2][10010];
//int wine[10010];
//
//int biggest(int a, int b, int c) {
//	int temp = max(a, b);
//	temp = max(temp, c);
//	return temp;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) 
//		cin >> wine[i];
//	
//	dp[0][0] = 0;
//	dp[1][0] = 0;
//	dp[0][1] = wine[1];
//	dp[1][2] = 0;
//
//	for (int i = 2; i <= n; i++) {
//		dp[0][i] = biggest(dp[0][i - 1], dp[0][i - 2] + wine[i], dp[1][i - 2] + wine[i]);
//		dp[1][i] = max(dp[1][i-1],dp[0][i - 1] + wine[i]);
//	}
//	int a = max(dp[0][n - 1], dp[1][n - 1]);
//	int b = max(dp[0][n], dp[1][n]);
//	cout << max(a,b);
//
//	return 0;
//}