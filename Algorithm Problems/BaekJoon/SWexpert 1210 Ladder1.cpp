//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <functional>
//#include <queue>
//#include <stack>
//#include <string.h>
//#define pair pair <int, int> 
//using namespace std;
//int ladder[110][110], visited[110][110];
//int dr[] = { 0,0,-1 };
//int dc[] = { -1,1,0 };
//
//int main() {
//	int ten = 10;
//	while (ten--) {
//		int index, dest, X; cin >> index;
//		for (int i = 0; i < 110; i++) {
//			memset(ladder[i], 0, sizeof(int) * 110);
//			memset(visited[i], 0, sizeof(int) * 110);
//		}
//		for(int r=0;r<100;r++)
//			for (int c = 0; c < 100; c++) {
//				cin >> ladder[r][c];
//				if (ladder[r][c] == 2)
//					dest = c;
//			}
//
//		int row = 99;
//		int col = dest;
//		visited[row][col] = 1;
//		while (true) {
//			for (int i = 0; i < 3; i++) {
//				int newR = row + dr[i];
//				int newC = col + dc[i];
//
//				if (newR >= 0 && newC >= 0 && newR < 100 && newC < 100 && ladder[newR][newC] == 1 && !visited[newR][newC]) {
//					row = newR; col = newC;
//					visited[newR][newC] = 1;
//					break;
//				}
//			}
//			if (row == 0) {
//				X = col;
//				break;
//			}
//		}
//
//
//
//		printf("#%d %d\n", index, X);
//	}
//
//
//
//
//	return 0;
//}