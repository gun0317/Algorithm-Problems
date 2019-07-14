//#include <iostream>
//using namespace std;
//int dp[100010] = { 1,1,3 };
//
////dp[i] = dp[i-1] + dp[i-2] * 2;
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 3; i <= n; i++) 
//		if(!dp[i])
//			dp[i] =( dp[i - 1] + dp[i - 2] * 2)%20100529;
//	
//	printf("%d\n", dp[n]);
//	
//}