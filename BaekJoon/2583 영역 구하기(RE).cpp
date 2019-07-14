//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <functional>
//#include <stack>
//#include <queue>
//#include <string.h> // test caseº° memset»ç¿ë
//#define pair pair <int,int>
//#define boundary newR>=0&&newC>=0&&newR<M&&newC<N
//using namespace std;
//int dr[] = { -1,1,0,0 };
//int dc[] = { 0,0,-1,1 };
//int N, M, K, map[101][101], visited[101][101], area[101];
//
//void DFS(pair cur,int idx) {
//	visited[cur.first][cur.second] = 1;
//	for (int i = 0; i < 4; i++) {
//		int newR = cur.first + dr[i];
//		int newC = cur.second + dc[i];
//		if (boundary && !map[newR][newC] && !visited[newR][newC])
//			DFS(make_pair(newR, newC),idx);
//	}
//	area[idx]++;
//}
//
//int main() {
//	cin >> M >> N >> K;
//	int lr, lc, rr, rc;
//	for (int i = 0; i < K; i++) {
//		cin >> lc >> lr >> rc >> rr;
//		for (int r = lr; r < rr; r++)
//			for (int c = lc; c < rc; c++)
//				map[r][c] = 1;
//	}
//	
//	int idx = 0, components = 0;
//	for (int r = 0; r < M; r++)
//		for (int c = 0; c < N; c++) {
//			if (!visited[r][c] && !map[r][c]) {
//				DFS(make_pair(r, c), idx++);
//				components++;
//			}
//		}
//	sort(area, area + components);
//	cout << components << endl;
//	for (int i = 0; i < components; i++) {
//		cout << area[i] << " ";
//	}
//
//	return 0;
//}