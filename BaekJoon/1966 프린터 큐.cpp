//#include <iostream>
//#include <vector>
//using namespace std;
//int ans;
//vector <pair <int,int> > v;
//
//int main() {
//	int T; cin >> T;
//	while (T--) {
//		int N, idx, temp; cin >> N >> idx;
//		v.clear();	//각 테스트 별 새로운 vector 이용
//		for (int i = 0; i < N; i++) {
//			cin >> temp;
//			v.push_back(make_pair(0, temp));
//		}
//		v[idx].first = 1;	//이용자가 원하는 자료임을 표시
//		
//		ans = 0;
//		while (1) {
//			//첫번째와 그 뒤의 중요도들을 비교해서 중요도가 더 큰 원소가
//			//하나라도 있으면 첫 원소를 제일 뒤로 보냄 + flag증가
//			//첫원소가 중요도 제일 높은거면 flag=0
//			int flag = 0;
//			for (int i = 1; i < v.size(); i++) {
//				if (v[0].second < v[i].second) {
//					int tempFirst = v[0].first;	//첫 자료의 정보 저장(first)
//					int tempSec = v[0].second;	//첫 자료의 정보 저장(second)
//					v.erase(v.begin());	//첫 자료를 지움
//					v.push_back(make_pair(tempFirst, tempSec));	//첫 자료를 제일 뒤로 보냄
//					flag++;
//					break;
//				}
//			}
//
//			//flag가 0, 즉 첫 원소의 중요도가 젤 높을때.(print 되는 경우)
//			if (!flag){
//				ans++;
//				if (v[0].first == 1)	//목표 도달->반복문 break
//					break;
//				else 
//					v.erase(v.begin());
//			}
//		}
//
//		cout << ans << endl;
//	}
//
//	return 0;
//}