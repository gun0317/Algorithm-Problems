//#include <iostream>
//#include <string.h>
//#include <algorithm>
//#define MAX_N 1010
//using namespace std;
//
//int runner[MAX_N];
//int passer[MAX_N];
//int candidate[MAX_N];
//
//int main() {
//	int T, testcase;
//	cin >> T;
//	testcase = 1;
//
//	while (T--) {
//		int N, M, temp, num = 0, j = 0, flag = 0, flag2 = 0;
//		cin >> N >> M;
//		memset(runner, 0, sizeof(int) * MAX_N);
//		memset(passer, 0, sizeof(int) * MAX_N);
//		memset(candidate, 0, sizeof(int) * MAX_N);
//		for (int i = 1; i <= M; i++) {
//			//scanf(" %d", &temp);
//			cin >> temp;
//			num += temp;
//			while (temp--) runner[j++] = i;
//		}
//		sort(runner, runner + num);
//		
//		for (int i = 0; i < N; i++) {
//			//scanf(" %d", &temp);
//			cin >> temp;
//			passer[i] = temp;
//		}
//
//		if (N == num){
//			sort(passer, passer + N);
//			for (int l = 0; l < num; l++) {
//				if (passer[l] == runner[l]) {
//					flag++;
//				}
//				else break;
//			}
//			if (flag == num) {
//				printf("#%d 1\n", testcase);
//				flag2 = 1;
//			}
//		}
//		/*
//		1
//		2 5
//		0 0 1 0 0
//		1 3
//*/
//		else if(N > num)
//			for (int i = 0; i < N - num + 1; i++) {
//				int idx = i;
//				flag = 0;
//				for (j = 0; j < num; j++) {
//					candidate[j] = passer[idx++];
//				}
//				sort(candidate, candidate + num);
//				for (int l = 0; l < num; l++) {
//					if (candidate[l] == runner[l]) {
//						flag++;
//					}
//					else break;
//				}
//				if (flag == num) {
//					printf("#%d %d\n", testcase, idx - num + 1);
//					flag2 = 1;
//					break;
//				}
//			}
//
//		if(flag2 == 0) printf("#%d 0\n", testcase);
//
//		testcase++;
//	}
//
//
//	return 0;
//}