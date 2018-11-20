//#include <iostream>
//
//using namespace std;
//int base[3], candidates[1000];
//int N;
//int temp, s, b;
//
//void divide(int * arr, int input) {
//
//	arr[0] = input / 100;
//	input -= arr[0] * 100;
//	arr[1] = input / 10;
//	input -= arr[1] * 10;
//	arr[2] = input;
//}
//
//bool isNotAns(int candidate) {
//	int candi[3],localS=0,localB=0;
//	divide(candi,candidate);
//	for(int i=0;i<3;i++)
//		for (int j = 0; j < 3; j++) {
//			if (base[i] == candi[j]) {
//				if (i == j)
//					localS++;
//				else
//					localB++;
//			}
//		}
//	if (localS == s && localB == b)
//		return 0;
//	return 1;
//}
//
//int main() {
//	for (int i = 123; i < 988; i++) {
//		candidates[i] = i;
//		int cand[3];
//		divide(cand, i);
//		if (cand[0] == cand[1] || cand[1] == cand[2] || cand[0] == cand[2] || cand[0] == 0 || cand[1] == 0 || cand[2] == 0)
//			candidates[i] = 0;
//	}
//
//	 cin >> N;
//	for (int i = 0; i < N; i++) {
//		
//		cin >> temp >> s>> b;
//		
//		//조건을 한자리씩 뜯음
//		divide(base, temp);
//
//		for (int j = 123; j < 988; j++) {
//			if (candidates[j] != 0)
//			{
//				if (isNotAns(candidates[j]))
//					candidates[j] = 0;
//			}
//		}
//	}
//	int ans = 0;
//	for (int i = 123; i < 988; i++)
//		if (candidates[i] != 0)
//			ans++;
//	cout << ans << endl;
//
//
//	return 0;
//}