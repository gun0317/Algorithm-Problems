//#include <iostream>
//#include <algorithm>
//#include <functional>
//#include <string.h>
//using namespace std;
//
//char input[1010];
//char ans[2020];
//int main() {
//	int T, testcase;
//	cin >> T;
//	testcase = 1;
//
//	while (T--) {
//		int n;
//		cin >> n;
//		memset(input, 0, sizeof(char) * 1010);
//		memset(ans, 0, sizeof(char) * 2020);
//		for (int i = 0; i < n; i++) {
//			cin >> input[i];
//		}
//		char first;
//		int front, back;
//		front = back = 1010;
//		first = ans[1010] = input[0];
//		for (int i = 1; i < n; i++) {
//			if (input[i] >= first) {
//				ans[--front] = input[i];
//				first = input[i];
//			}
//			else
//				ans[++back] = input[i];
//			
//		}
//		printf("#%d ", testcase);
//		for (int i = front; i < back+1; i++) {
//			printf("%c", ans[i]);
//		}
//		printf("\n");
//
//		testcase++;
//	}
//
//
//	return 0;
//}