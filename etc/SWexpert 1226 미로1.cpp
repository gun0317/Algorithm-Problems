//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <string.h>
//#define pair pair <int,int> 
//#define boundary newR<16 && newC<16 && newR >=0 && newC>=0
//using namespace std;
//pair start, goal;
//int dr[] = { -1,1,0,0 };
//int dc[] = { 0,0,-1,1 };
//int visited[20][20];
//int map[20][20];
//
//int BFS() {
//	for (int i = 0; i < 20; i++) {
//		memset(visited[i], 0, sizeof(int) * 20);
//	}
//	queue <pair> q;
//	q.push(start);
//	visited[start.first][start.second] = true;
//
//	while (!q.empty()) {
//		pair cur = q.front();
//		q.pop();
//	
//
//		for (int i = 0; i < 4; i++) {
//			int newR = cur.first + dr[i];
//			int newC = cur.second + dc[i];
//			if (map[newR][newC] == 3) {
//				return 1;
//			}
//
//			if (visited[newR][newC] == false && map[newR][newC] == 0 && boundary) {
//				visited[newR][newC] = true;
//				q.push(make_pair(newR, newC));
//			}
//		}
//
//	}
//
//	return 0;
//}
//int main() {
//	int testCase = 10;
//	while (testCase--) {
//		int testIndex;
//		cin >> testIndex;
//		for(int i=0;i<20;i++)
//			memset(map[i], 0, sizeof(int) * 20);
//		for (int r = 0; r < 16; r++) {
//			for (int c = 0; c < 16; c++) {
//				scanf(" %1d", &map[r][c]);
//				if (map[r][c] == 2)
//					start = make_pair(r, c);
//				if (map[r][c] == 3)
//					goal = make_pair(r, c);
//			}
//		}
//		printf("#%d %d\n", testIndex, BFS());
//	}
//
//
//	return 0;
//}