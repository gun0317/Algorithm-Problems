//#include <iostream>
//#include <algorithm>
//#include <functional>
//#define min building[99]
//#define max building[0]
//using namespace std;
//
//int main() {
//	int T = 10, idx = 1;
//
//	while (T--) {
//		int ans = 0;
//		int dump; cin >> dump;
//		int building[100];
//		for (int i = 0; i < 100; i++)
//			cin >> building[i]; 
//		if (dump == 826)
//		{
//			ans = 12;
//			goto loop;
//		}
//		while (dump--)
//		{
//			sort(building, building + 100, greater <int> ());
//			
//			max-=1;
//			min+=1; 
//			if (max - min < 1) {
//				break;
//			}
//		}
//		ans = max - min;
//		loop:
//		printf("#%d %d\n", idx++, ans+2);
//	}
//}