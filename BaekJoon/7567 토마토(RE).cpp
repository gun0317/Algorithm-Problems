#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stack>
#include <queue>
#include <string.h> // test case�� memset���
#define pair pair <int,int>
#define boundary newR>=0&&newC>=0&&newR<N&&newC<M
using namespace std;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int N, M, K, map[1001][1001], visited[1001][1001];
queue <pair> q;

void BFS() {
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		visited[row][col] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newR = row + dr[i];
			int newC = col + dc[i];
			
			if (boundary && !visited[newR][newC] && map[newR][newC] == 0) {
				visited[newR][newC] = 1;
				map[newR][newC] = map[row][col] + 1;
				q.push(make_pair(newR,newC));
			}
		}

	}
}

int main() {
	cin >> M >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++) {
			scanf(" %d", &map[r][c]);
			if(map[r][c] ==1)
				q.push(make_pair(r,c));
		}

	BFS();
	int max = 0;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++) {
			if (map[r][c] == 0) {
				cout << -1; return 0;
			}
			if (max < map[r][c])
				max = map[r][c];
		}
	cout << max-1;
	return 0;
}