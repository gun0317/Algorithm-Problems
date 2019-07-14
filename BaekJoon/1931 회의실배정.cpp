//#include <iostream>
//#include <algorithm>
//#include <vector>
//#define pair pair <int,int> 
//using namespace std;
//int N;
//vector <pair> v;
//
//int main() {
//	cin >> N;
//	v.resize(N);
//	for (int i = 0; i < N; i++) 
//		cin >> v[i].second >> v[i].first;
//	sort(v.begin(), v.end());
//	int endtime = v[0].first;
//	int cnt = 1;
//	for (int i = 1; i < N; i++) {
//		if (endtime > v[i].second)
//			continue;
//		else {
//			endtime = v[i].first;
//			cnt++;
//		}
//	}
//	cout << cnt;
//	
//	return 0;
//}