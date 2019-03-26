//#include <iostream>
//#include <string.h>
//#define up 1
//#define down 2
//#define left 3
//#define right 4
//#define cur map[r][c]
//#define next next_map[next_r][next_c]
//using namespace std;
//
//typedef struct {
//	int cnt, dir, maxCnt;
//}node;
//node map[100][100];
//node next_map[100][100];
//node NULLNODE;
//int dr[] = { -1,1,0,0 };
//int dc[] = { 0,0,-1,1 };
//int N, M, K;
//
//
//void move() {
//	for (int r = 0; r < N; r++) {
//		for (int c = 0; c < N; c++) {
//			if (cur.cnt > 0) {
//				//dir에 따른 상하좌우 이동 후 좌표
//				int next_r = r + dr[cur.dir - 1];
//				int next_c = c + dc[cur.dir - 1];
//				//경계점에서 마릿수, 방향 처리
//				if (next_r == 0 || next_c == 0 || next_r == N - 1 || next_c == N - 1) {
//					cur.cnt /= 2;
//					cur.maxCnt = cur.cnt;
//					if (cur.cnt == 0) {
//						map[r][c] = NULLNODE;
//						continue;
//					}
//
//					if (cur.dir == up) cur.dir = down;
//					else if (cur.dir == down) cur.dir = up;
//					else if (cur.dir == left) cur.dir = right;
//					else if (cur.dir == right) cur.dir = left;
//				}
//				
//				next.cnt += cur.cnt;
//				if (next.maxCnt < cur.maxCnt) {
//					next.dir = cur.dir;
//					next.maxCnt = cur.maxCnt;
//				}
//				else {
//					next.dir;
//					next.cnt;
//					next.maxCnt;
//				}
////기존에 있던 map의 값은 초기화 할 필요없음(for문이 다시 방문할 일 없음)
//			}
//		}
//	}
//
//		//map = next_map으로 교체
//	for (int r = 0; r < N; r++)
//		for (int c = 0; c < N; c++)
//		{
//			map[r][c].cnt = map[r][c].maxCnt = next_map[r][c].cnt;
//			map[r][c].dir = next_map[r][c].dir;
//		}
//	//next_map 초기화
//	for (int i = 0; i < N; i++) memset(next_map[i], 0, sizeof(node)*N);
//}
//
//int main() {
//	int T, idx = 1; cin >> T;
//	NULLNODE.cnt = 0;
//	NULLNODE.dir = 0;
//	NULLNODE.maxCnt = 0;
//	while (T--) {
//		cin >> N >> M >> K;
//		for (int i = 0; i < 100; i++)
//			memset(map[i], 0, sizeof(node)*100);
//		for (int i = 0; i < K; i++) {
//			int r, c, count, d;
//			cin >> r >> c >> count >> d;
//			map[r][c].cnt = map[r][c].maxCnt = count;
//			map[r][c].dir = d;
//		}
//
//		while (M--)
//			move();
//
//		int ans = 0;
//		for (int r = 0; r < N; r++)
//			for (int c = 0; c < N; c++)
//				ans += map[r][c].cnt;
//
//		printf("#%d %d\n", idx++, ans);
//	}
//}