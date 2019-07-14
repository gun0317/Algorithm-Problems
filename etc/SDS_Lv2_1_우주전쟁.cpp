//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <functional>
//#include <queue>
//#include <stack>
//#include <string.h>
//#define pair pair <int, int>
//using namespace std;
//
//vector <pair> missiles;
//int alien_N, missile_N, barrier, power, ammo, flag, ans;
//
//int endCondition() {
//	int size = 0, sums = 0, temp;
//	for (int i = 0; i < missiles.size(); i++) size += missiles[i].second;
//	for (int i = missiles.size() - 1; i > -1; i++) {
//		if (missiles[i].second > 1 && missiles[i].first * 2 > barrier) return 1;
//		else if (missiles[i].second == 1) {
//			temp = i;
//			sums += missiles[i].first;
//		}
//
//	}
//	if (size == 0) return 0;
//	else if (alien_N == 0) return 0;
//	else if (missiles.back().second >= 2) {
//		if (missiles.back().first * 2 >= barrier)
//			return 1;
//		else
//			return 0;
//	}
//	else if (missiles.back().second == 1)
//	{
//		if (missiles.back().first + missiles[missiles.size() - 2].first >= barrier)
//			return 1;
//		else
//			return 0;
//	}
//}
//
//void missileReduceByOne(int idx) {
//	missiles[idx].second--;
//	//if (missiles[idx].second == 0)
//	//	missiles.erase(missiles.begin() + idx);
//}
//
//
//void binary(int left, int right, int target, int cur) {
//	if (left > right)
//		return;
//	int mid = (left + right) / 2;
//	if ((missiles[mid].first) < target) binary(mid + 1, right, target, cur);
//	else if ((missiles[mid].first) > target) binary(left, mid - 1, target, cur);
//	else if ((missiles[mid].first) == target) {
//		if ((mid == cur) && (missiles[cur].second < 2))
//			return;
//		while (missiles[cur].second > 0 && missiles[mid].second > 0) {
//			ans += missiles[mid].first + missiles[cur].first;
//			//missileReduceByOne(mid);
//			//missileReduceByOne(cur);
//			missiles[cur].second--;
//			missiles[mid].second--;
//			alien_N--;
//			if (alien_N == 0) return;
//		}
//		
//		return;
//		
//	}
//}
//
//int main() {
//	int T, testcase;
//	cin >> T;
//	testcase = 1;
//
//	while (T--) {
//		missiles.clear();
//		ans = 0;
//		cin >> alien_N >> missile_N >> barrier;
//		for (int i = 0; i < missile_N; i++) {
//			cin >> power >> ammo;
//			missiles.push_back(make_pair(power, ammo));
//		}
//		sort(missiles.begin(), missiles.end());
//
//		int target = alien_N * barrier;
//		flag = 0;
//		int idx = 0;
//
//		while (endCondition()) {
//			//(exact+i)-powered missiles. <one shot>
//			for (int i = 0; i < missiles.size(); i++) 
//				while (missiles[i].first == (barrier + idx) && missiles[i].second > 0) {
//					ans += missiles[i].first;
//					//missileReduceByOne(i);
//					missiles[i].second--;
//					alien_N--;
//					if (alien_N == 0) break;
//				}
//			if (alien_N == 0) break;
//
//			//binary searching <two-shotable> missiles whose power is (exact+i)
//			for (int i = 0; i < missiles.size(); i++) {
//				if (alien_N == 0) break;
//				if (missiles[i].first < barrier);
//					binary(i, missiles.size() - 1, barrier + idx - missiles[i].first, i);
//			}
//			if (alien_N == 0) break;
//
//			idx++;
//		}
//		if(alien_N > 0)	printf("#%d -1\n", testcase);
//		else printf("#%d %d\n", testcase, ans);
//		testcase++;
//	}
//	return 0;
//}