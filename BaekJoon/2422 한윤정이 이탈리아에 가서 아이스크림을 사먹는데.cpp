//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int N, M;
//vector <vector <int> > rules;
//
//bool ruleObey(int op1, int op2) {
//	for (int i = 0; i < rules[op1].size(); i++) 
//		if (op2 == rules[op1][i]) return 1;
//
//	return 0;
//}
//
//int main() {
// 	cin >> N >> M;
//	int r1, r2, temp;
//	rules.resize(N+1);
//	for (int i = 0; i < M; i++) {
//		cin >> r1 >> r2;
//		if (r1 > r2) {
//			temp = r2;
//			r2 = r1;
//			r1 = temp;
//		}
//		rules[r1].push_back(r2);
//	}
//
//	for (int i = 1; i < N+1; i++) 
//		if (rules[i].size() > 0)
//			sort(rules[i].begin(), rules[i].end());
//	
//	int cnt = 0;
//
//	for (int f = 1; f <= N; f++) {
//		for (int s = f + 1; s <= N; s++) {
//			if(rules[f].size() > 0)
//				if (ruleObey(f, s)) {//f와 s사이에 rules에 해당하는 예외 케이스가 있는지 탐색
//					continue;
//				}
//			for (int t = s + 1; t <= N; t++) {	//s와 t사이에 rules에 해당하는 예외 케이스가 있는지 && f와 t사이에 " 반복.
//				if (ruleObey(s, t)) continue;
//				if (ruleObey(f, t)) continue;
//				cnt++;
//			}
//		}
//	}
//	cout << cnt;
//	return 0;
//}