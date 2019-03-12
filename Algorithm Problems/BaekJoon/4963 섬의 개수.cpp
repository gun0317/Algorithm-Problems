//#include <iostream>
//#include <queue>
//#include <string.h>
//#define pair pair <int, int> 
//#define boundary newR < h && newC < w && newR>=0 && newC>=0
//using namespace std;
//int moves[][2] = { {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{1,-1}, {-1,1} };
//int map[60][60], visited[60][60], ans, w, h;
//queue <pair> q;
//
//void BFS() {
//	pair cur = q.front();
//	q.pop();
//	if (map[cur.first][cur.second] == 1)
//	{
//		ans++;
//		map[cur.first][cur.second] = 0;
//	}
//	else return;
//	
//	queue <pair> qCur;
//	qCur.push(cur);
//
//	while (!qCur.empty()) {
//		pair cur2 = qCur.front();
//		qCur.pop();
//
//		for (int i = 0; i < 8; i++) {
//			int newR = cur2.first + moves[i][0];
//			int newC = cur2.second + moves[i][1];
//
//			if (boundary && map[newR][newC] == 1) {
//				qCur.push(make_pair(newR, newC));
//				map[newR][newC] = 0;
//			}
//		}
//
//
//	}
//
//}
//
//int main() {
//	while (true) {
//		cin >> w >> h;
//		if (w == 0 && h == 0) {
//			return 0;
//		}
//
//		while (!q.empty())q.pop();
//
//		for (int i = 0; i < 60; i++) {
//			memset(map[i], 0, sizeof(int) * 60);
//			memset(visited[i], 0, sizeof(int) * 60);
//		}
//
//		for (int r = 0; r < h; r++) {
//			for (int c = 0; c < w; c++) {
//				cin >> map[r][c];
//				if (map[r][c] == 1) {
//					q.push(make_pair(r, c));
//				}
//			}
//		}
//		ans = 0;
//		int size = q.size();
//		for (int i = 0; i < size; i++)
//			BFS();
//		cout << ans << endl;
//	}
//
//
//
//
//	return 0;
//}