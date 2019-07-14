//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int scores[310];
//int dp[2][310];
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) 
//		cin >> scores[i];
//	dp[0][0] = dp[0][1] = 0;
//	dp[1][0] = dp[1][1] = 0;
//	dp[0][1] = dp[1][1] = scores[1];
//	
//	for (int i = 2; i <= n; i++) {
//		dp[0][i] = dp[1][i-1] + scores[i];
//		dp[1][i] = max(dp[0][i-2], dp[1][i-2]) + scores[i];
//	}
//	int a = dp[0][n];
//	int b = dp[1][n];
//	int ans = a > b ? a : b;
//	cout << ans << endl;
//
//
//	return 0;
//}