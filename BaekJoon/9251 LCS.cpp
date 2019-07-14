//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//int arr[1010][1010];
//
//int main() {
//	string s1, s2;
//	cin >> s1 >> s2;
//	int size1 = s1.size();
//	int size2 = s2.size();
//
//	for (int r = 1; r <= size1; r++) {
//		for (int c = 1; c <= size2; c++) {
//			if (s1[r-1] == s2[c-1]) {
//				arr[r][c] = arr[r - 1][c - 1] + 1;
//			}
//			else {
//				arr[r][c] = max(arr[r - 1][c], arr[r][c - 1]);
//			}
//		}
//	}
//
//	cout << arr[size1][size2] << endl;
//
//	return 0;
//}