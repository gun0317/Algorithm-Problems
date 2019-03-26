//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <functional>
//#include <queue>
//#include <stack>
//#include <string.h>
//#define pair pair <int, int> 
//#define here [cur.first][cur.second]
//#define up [cur.first-1][cur.second]
//#define down [cur.first+1][cur.second]
//#define left [cur.first][cur.second-1]
//#define right [cur.first][cur.second+1]
//#define boundary ;
//using namespace std;
//int T, N, M, R, C, L,ans;
//int map[50][50], visited[50][50];
//
//void BFS() {
//	queue <pair> q;
//	q.push(make_pair(R, C));
//	visited[R][C] = 1;
//	ans++;
//	while (!q.empty()) {
//		//we need depth -> visited[newR][newC] = visited[row][col]+1;
//		pair cur = q.front();
//		q.pop();
//		int flagUp = 0, flagDown = 0, flagLeft = 0, flagRight = 0;
//		switch (map here)
//		{
//		case 1: {//╩С,го,аб,©Л
//			flagUp++; flagDown++; flagLeft++; flagRight++;
//			break;
//		}
//		case 2: {//╩С,го	
//			flagUp++; flagDown++;
//			break;
//		}
//		case 3:{//аб,©Л
//			flagLeft++; flagRight++;
//			break;
//		}
//		case 4:{//╩С,©Л
//			flagUp++; flagRight++;
//			break;
//		}
//		case 5:{//го,©Л
//			flagDown++; flagRight++;
//			break;
//		}
//		case 6:{//го,аб
//			flagDown++; flagLeft++;
//			break;
//		}
//		case 7:{//╩С,аб
//			flagUp++; flagLeft++;
//			break;
//		}
//		default:
//			break;
//		}
//
//		//Up
//		if(flagUp)
//		if (cur.first - 1 >= 0 && !visited up)
//			if (map up == 1 || map up == 2 || map up == 5 || map up == 6) {
//				visited up = visited here + 1;
//				ans++;
//				if (visited up < L)
//					q.push(make_pair(cur.first - 1, cur.second));
//			}
//		//Down
//		if(flagDown)
//		if (cur.first + 1 < N && !visited down)
//			if (map down == 1 || map down == 2 || map down == 4 || map down == 7) {
//				visited down = visited here + 1;
//				ans++;
//				if (visited down < L)
//					q.push(make_pair(cur.first + 1, cur.second));
//			}
//		//left
//		if(flagLeft)
//		if (cur.second - 1 >= 0 && !visited left)
//			if (map left == 1 || map left == 3 || map left == 4 || map left == 5) {
//				visited left = visited here + 1;
//				ans++;
//				if (visited left < L)
//					q.push(make_pair(cur.first, cur.second - 1));
//			}
//		//right
//		if(flagRight)
//		if (cur.second + 1 <M && !visited right)
//			if (map right == 1 || map right == 3 || map right == 6 || map right == 7) {
//				visited right = visited here + 1;
//				ans++;
//				if (visited right < L)
//					q.push(make_pair(cur.first, cur.second + 1));
//			}
//	}
//}
//
//int main() {
//	cin >> T; int index = 1;
//	while (T--) {
//		//initialize
//		cin >> N >> M >> R >> C >> L;
//		ans = 0;
//		for (int i = 0; i < 50; i++) {
//			memset(map[i], 0, sizeof(int) * 50);
//			memset(visited[i], 0, sizeof(int) * 50);
//		}
//		for (int r = 0; r < N; r++)
//			for (int c = 0; c < M; c++)
//				cin >> map[r][c];
//		
//		BFS();
//		if (L == 1)
//			ans = 1;
//
//		printf("#%d %d\n", index++, ans);
//
//	}
//
//
//
//
//	return 0;
//}