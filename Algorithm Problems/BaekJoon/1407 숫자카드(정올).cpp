//#include <iostream>
//using namespace std;
//int dp[2][310], scores[310];
//int main() {
//	int N;
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//		cin >> scores[i];
//
//	for (int i = 1; i <= N; i++) {
//		dp[0][i] = dp[1][i - 2] + scores[i];
//		dp[1][i] = dp[0][i - 1] + scores[i];
//	}
//	cout << (dp[0][N] > dp[1][N]) ? dp[0][N] : dp[1][N];
//
//
//	return 0;
//}