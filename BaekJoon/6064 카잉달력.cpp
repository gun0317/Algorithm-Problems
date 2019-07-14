//#include <iostream>
//using namespace std;
//
//int main() {
//	int T; cin >> T;
//	while (T--) {
//		int ans = -1;
//		int M, N, x, y;
//		cin >> M >> N >> x >> y;
//		
//		int flag = 0, A = 0, B = 0;
//
//		while (M*A + x != N * B + y) {
//			if (M*A + x > N*B + y) B++;
//			else if (M*A + x == N * B + y) break;
//			else if (A > 40000) { flag++; break; }
//			else A++;
//		}
//
//		ans = M * A + x;
//
//		if (flag > 0) {
//			ans = -1;
//		}
//
//		cout << ans << endl;
//	}
//
//	return 0;
//}