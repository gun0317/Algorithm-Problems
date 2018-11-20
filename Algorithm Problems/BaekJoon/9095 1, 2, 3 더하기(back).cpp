//#include <iostream>
//using namespace std;
//int input, ans;
//
//void back(int sum) {
//	if (sum == input) {
//		ans++;
//		return;
//	}
//	for (int i = 1; i <= 3; i++) {
//		if (sum + i <= input)
//			back(sum + i);
//	}
//}
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> input;
//		ans = 0;
//		back(0);
//		cout << ans << endl;
//	}
//	return 0;
//}