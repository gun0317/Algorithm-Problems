//#include <iostream>
//#include <cmath>
//using namespace std;
//int A[1000010], B, C, DP[1000010];
//
//int main() {
//	int N;
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		cin >> A[i];
//	}
//	cin >> B >> C;
//	long long ans = 0;
//
//
//	for (int i = 1; i <= N; i++) {
//		int minusB = A[i] - B;
//
//		//DP로 해결될 때
//		if (DP[A[i]] > 0) ans += DP[A[i]];
//
//		//총 감독관 한 명으로 cover될 때
//		else if (minusB <= 0) {
//			DP[A[i]] = 1;
//			ans += DP[A[i]];
//		}
//		//부 감독관이 필요할 때
//		else {
//			if (minusB % C == 0) {
//				DP[A[i]] = 1 + minusB / C;
//				ans += DP[A[i]];
//			}
//			else {
//				DP[A[i]] = 2 + minusB / C;
//				ans += DP[A[i]];
//			}
//
//		}
//
//
//	}
//
//
//	cout << ans << endl;
//
//	return 0;
//}