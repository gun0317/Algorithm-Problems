#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stack>
#include <queue>
#include <string.h>
#define pair pair <int,int>
#define boundary newR>=0&&newC>=0&&newR<N&&newC<M
using namespace std;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int N, M, K, map[1001][1001], visited[1001][1001];

void DFS(pair cur) {
	visited[cur.first][cur.second] = 1;
	for (int i = 0; i < 4; i++) {
		int newR = cur.first + dr[i];
		int newC = cur.second + dc[i];
		if (boundary && !visited[newR][newC] && map[newR][newC]) {
			DFS(make_pair(newR, newC));
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		int cnt = 0, u, v;
		for (int i = 0; i < K; i++) {
			cin >> u >> v;
			map[v][u] = 1;
		}
		for (int r = 0; r < N; r++)
			for (int c = 0; c < M; c++) {
				if (map[r][c] && !visited[r][c]) {
					cnt++;
					DFS(make_pair(r, c));
				}
			}
		cout << cnt << endl;
		for (int i = 0; i < 60; i++) {
			memset(map[i], 0, sizeof(int) * 60);
			memset(visited[i], 0, sizeof(int) * 60);
		}
	}

	return 0;
}