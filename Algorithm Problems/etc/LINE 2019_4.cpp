//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//vector <int> stk;
//
//int main() {
//	int N;
//	int top = 0, ans=0, height;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> height;
//		if (stk.size() > 0 && stk[0] <= height) {
//			int temp = 0;
//			while(!stk.empty()) {
//				temp++;
//				stk.pop_back();
//			}
//			if (temp > ans) ans = temp;
//		}
//		stk.push_back(height);
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}