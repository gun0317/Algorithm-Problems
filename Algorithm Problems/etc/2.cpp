//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector <pair <int, int> > v;
//
//int main() {
//	int n;
//	cin >> n;
//	while (n-- > 0) {
//		int x, y, w, h;
//		cin >> x >> y >> w >> h;
//		// @todo Write your code here.
//		v.push_back(make_pair(x + 100 * y, (x + w) + (y + h) * 100));
//	}
//	sort(v.begin(), v.end());
//
//	int size = v.size();
//	int max = 0, cnt = 0;
//	for (int x = 0; x < 100; x++) {
//		for (int y = 0; y < 100; y++) {
//			cnt = 0;
//			for (int i = 0; i < size; i++) {
//				int leftX = v[i].first % 100;
//				int leftY = v[i].first / 100;
//				int rightX = v[i].second % 100;
//				int rightY = v[i].second / 100;
//				if (x >= leftX && y >= leftY && x <= rightX && y <= rightY) {
//					cnt++;
//				}
//			}
//			if (max < cnt) max = cnt;
//		}
//	}
//	// @todo Write your code here.
//	cout << max << endl;
//	return 0;
//}
