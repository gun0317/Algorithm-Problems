//#include <iostream>
//#include <algorithm>
//#include <queue>
//#define pair pair <int,int>
//#define boundary newR>=0&&newC>=0&&newR<N&&newC<M
//using namespace std;
//int dr[] = { -1,1,0,0 };
//int dc[] = { 0,0,-1,1 };
//int N, M, K, map[110][110], visited[110][110];
//
//void BFS() {
//	queue <pair> q;
//	q.push(make_pair(0, 0));
//	visited[0][0] = 1;
//
//	while (!q.empty()) {
//		int row = q.front().first;
//		int col = q.front().second;
//		q.pop();
//		if (row == N - 1 && col == M - 1) {
//			cout << visited[row][col];
//			exit(1);
//		}
//
//		for (int i = 0; i < 4; i++) {
//			int newR = row + dr[i];
//			int newC = col + dc[i];
//
//			if (boundary && map[newR][newC] && !visited[newR][newC]) {
//				q.push(make_pair(newR, newC));
//				visited[newR][newC] = visited[row][col] + 1;
//			}
//		}
//	}
//
//
//
//}
//
//int main() {
//	cin >> N >> M;
//	for(int r=0;r<N;r++)
//		for (int c = 0; c < M; c++) {
//			scanf("%1d", &map[r][c]);
//		}
//
//	BFS();
//
//	return 0;
//}