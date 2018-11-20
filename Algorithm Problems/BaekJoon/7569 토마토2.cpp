//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <functional>
//#include <queue>
//#include <stack>
//#include <string.h>
//#define pair pair <int, int> 
//#define boundary newH<H && newC<M && newR<N && newR>=0 && newC>=0 && newH>=0
//using namespace std;
//int map[110][110][110];
//int M, N, H;
//int dr[] = { -1,1,0,0,0,0 };
//int dc[] = { 0,0,-1,1,0,0 };
//int dh[] = { 0,0,0,0,-1,1 };
//queue <pair> q;
//
//void BFS() {
//	
//	while (!q.empty()) {
//		int h = q.front().first;
//		int r = q.front().second / 1000;
//		int c = q.front().second % 1000;
//		q.pop();
//
//		for (int i = 0; i < 6; i++) {
//			int newH = h + dh[i];
//			int newR = r + dr[i];
//			int newC = c + dc[i];
//
//			if (boundary && map[newH][newR][newC] == 0) {
//				q.push(make_pair(newH, newR * 1000 + newC));
//				map[newH][newR][newC] = map[h][r][c] + 1;
//			}
//		}
//
//
//	}
//}
//
//int main() {
//	cin >> M >> N >> H;
//	for (int h = 0; h < H; h++)
//		for (int r = 0; r < N; r++)
//			for (int c = 0; c < M; c++){
//				scanf(" %d", &map[h][r][c]);
//				if (map[h][r][c] == 1)
//					q.push(make_pair(h, r * 1000 + c));
//			}
//	
//	BFS();
//	int max = 0;
//	for (int h = 0; h < H; h++)
//		for (int r = 0; r < N; r++)
//			for (int c = 0; c < M; c++)
//			{
//				if (max < map[h][r][c])
//					max = map[h][r][c];
//				if (map[h][r][c] == 0) {
//					cout << -1;
//					return 0;
//				}
//			}
//	
//	cout << max-1;
//	return 0;
//}