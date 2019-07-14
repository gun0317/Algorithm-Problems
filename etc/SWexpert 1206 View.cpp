//#include <iostream>
//#include <string.h>
//using namespace std;
//int buildings[1010];
//
//int main() {
//	int ten = 10;
//	while (ten--) {
//		int ground;
//		memset(buildings, 0, sizeof(buildings));
//		cin >> ground;
//		for (int i = 0; i < ground; i++) cin >> buildings[i];
//		int ans = 0;
//		for (int i = 0; i < ground-4; i++) {
//			int LL = buildings[i];
//			int L = buildings[i + 1];
//			int mid = buildings[i + 2];
//			int R = buildings[i + 3];
//			int RR = buildings[i + 4];
//
//			int biggerL = LL >= L ? LL : L;
//			int biggerR = RR >= R ? RR : R;
//
//			if (biggerL < mid && mid > biggerR) {
//				int bigger = biggerL <= biggerR ? biggerR : biggerL;
//				ans += mid - bigger;
//			}
//		}
//		cout << "#" << 10 - ten << " " << ans << endl;
//
//	}
//
//}