//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <functional>
//#include <stack>
//#include <queue>
//#include <string.h> // test caseº° memset»ç¿ë
//#define pair pair <int,int>
//#define boundary newR>=0&&newC>=0&&newR<R&&newC<C
//using namespace std;
//int dr[] = { -1,1,0,0 };
//int dc[] = { 0,0,-1,1 };
//int N, M, K, alpha[30];
//int R, C, ans =1;
//char map[30][30];
//
//
//void DFS(int r, int c, int depth) {
//	alpha[map[r][c] - 'A'] = 1;
//	if (ans < depth) {
//		ans = depth;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		int newR = r + dr[i];
//		int newC = c + dc[i];
//		if (boundary && !alpha[map[newR][newC] - 'A']) {
//			alpha[map[newR][newC] - 'A'] = 1;
//			DFS(newR, newC, depth + 1);
//			alpha[map[newR][newC] - 'A'] = 0;
//		}
//	}
//
//}
//
//int main() {
//	cin >> R >> C;
//	for(int row = 0;row<R;row++)
//		for (int col = 0; col < C; col++) {
//			scanf(" %1c", &map[row][col]);
//		}
//	DFS(0, 0, 1);
//	cout << ans;
//
//	return 0;
//}