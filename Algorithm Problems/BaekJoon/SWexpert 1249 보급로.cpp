//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <functional>
//#include <stack>
//#include <queue>
//#include <string.h> // test caseº° memset»ç¿ë
//#define pair pair <int,int>
//#define boundary newR>=0&&newC>=0&&newR<N&&newC<N
//#define worthVisiting visited[r][c] + map[newR][newC] <visited[newR][newC]
//using namespace std;
//int dr[] = { -1,1,0,0 };
//int dc[] = { 0,0,-1,1 };
//int N, M, K, map[101][101], visited[101][101];
//int t_case=1;
//int ans = 99999999;
//
//void BFS() {
//	for(int i=0;i<N;i++)
//		memset(visited[i], 999999, sizeof(int)*N);
//	queue <pair> q;
//	q.push(make_pair(0, 0));
//	visited[0][0] = map[0][0];
//
//	while (!q.empty()) {
//		int r = q.front().first;
//		int c = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int newR = r + dr[i];
//			int newC = c + dc[i];
//
//			if (boundary&&worthVisiting) {
//				visited[newR][newC] = visited[r][c] + map[newR][newC];
//				q.push(make_pair(newR, newC));
//			}
//		}
//
//	}
//
//
//}
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		for (int i = 0; i < N; i++) {
//			memset(map[i], 0, sizeof(int)*N);
//		}
//		cin >> N;
//		for(int r=0;r<N;r++)
//			for (int c = 0; c < N; c++) 
//				scanf(" %1d", &map[r][c]);
//
//		BFS();
//		
//		printf("#%d %d\n", t_case++, visited[N-1][N-1]);
//	}
//
//	return 0;
//}