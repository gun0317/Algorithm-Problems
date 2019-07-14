#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define BOUNDARY newR<N&&newC<N&&newR>=0&&newC>=0
#define DIFFERENCE abs(map[cur.first][cur.second]-map[newR][newC])
using namespace std;

bool endFlag = false;
int lowerBound, biggerBound, ans, N, indexes, map[55][55], visited[55][55];
int dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 };
vector <pair <int, int>> v[2510];

void BFS(int r, int c);
void move();

int main() {
	cin >> N >> lowerBound >> biggerBound;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> map[r][c];
	
	while (1) {
		indexes = 1;
		endFlag = true;
		for (int i = 0; i < N; i++) memset(visited[i], 0, sizeof(int)*N);
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				if(!visited[r][c])
					BFS(r, c);
		if (endFlag == true) break;
		move();
		ans++;
	}

	cout << ans << endl;
	return 0;
}

void BFS(int r, int c) {
	queue <pair <int, int>> q;
	q.push({ r,c });
	v[indexes].push_back({ r,c });
	
	while (!q.empty()) {
		pair <int, int> cur = q.front();
		q.pop();
		if (!visited[cur.first][cur.second])
			visited[cur.first][cur.second] = indexes++;

		for (int i = 0; i < 4; i++) {
			int newR = cur.first + dr[i], newC = cur.second + dc[i];
			if (BOUNDARY && !visited[newR][newC]) {
				if (lowerBound <= DIFFERENCE && biggerBound >= DIFFERENCE) {
					visited[newR][newC] = visited[cur.first][cur.second];
					v[visited[cur.first][cur.second]].push_back({ newR,newC });
					q.push({ newR,newC });
					if (DIFFERENCE != 0) endFlag = false;
				}
			}
		}
	}

}

// reWrites the population according to its unions
void move() {
	for (int i = 0; i < 2510; i++) {
		if (v[i].size() <= 1) continue;
		int localSum = 0, localCnt = 0, localVal = 0, localSize = v[i].size();
		while (localSize-- > 0) {
			localSum += map[v[i][localSize].first][v[i][localSize].second];
			localCnt++;
		}
		localVal = localSum / localCnt;
		while (v[i].size() > 0) {
			map[v[i].back().first][v[i].back().second] = localVal;
			v[i].pop_back();
		}
	}
	for (int i = 0; i < 2510; i++) v[i].clear();
}