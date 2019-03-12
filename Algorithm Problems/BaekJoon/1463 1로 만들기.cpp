//#include <iostream>
//#include <string.h>
//using namespace std;
//int dp[100010];
//int cnt = 0;
//
//int cal(int n) {
//	if (dp[n] != -1) return dp[n] + cnt;
//	else if (n % 3 == 0) {
//		cnt++;
//		cal(n / 3);
//	}
//	else if (n % 2 == 0) {
//		cal(n / 2);
//		cnt++;
//	}
//	else {
//		cnt++;
//		cal(n - 1);
//	}
//}
//
//
//int main() {
//	int N;
//	cin >> N;
//	memset(dp, -1, sizeof(int) * 100010);
//	dp[0] = dp[1] = 0;
//	cout << cal(N);
//}