#include <iostream>
#include <queue>
#include <string.h>
#define BOUNDARY d
using namespace std;
int **visited;
int dr[] = { 1,2,1,2,-1,-2,-1,-2 }, dc[] = { 2,1,-2,-1,2,1,-2,-1 };

int BFS(int l, int sR, int sC, int gR, int gC);

int main() {
	int T;
	cin >> T;
	while (T--) {
		int l, r, c, goalR, goalC;
		cin >> l >> r >> c >> goalR >> goalC;
		visited = new int*[l + 1];
		for (int i = 0; i < l + 1; i++) visited[i] = new int[l + 1]();

		cout << BFS(l, r, c, goalR, goalC) - 1 << endl;
		for (int i = 0; i < l + 1; i++)
			free(visited[i]);
		free(visited);
	}
}

int BFS(int l, int sR, int sC, int gR, int gC) {
	queue <pair<int, int> > q;
	q.push({ sR,sC });
	visited[sR][sC] = 1;

	while (!q.empty()) {
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();
		if (curR == gR && curC == gC) {
			return visited[curR][curC];
		}

		for (int i = 0; i < 8; i++) {
			int newR = curR + dr[i];
			int newC = curC + dc[i];
			if (newR >= 0 && newR < l && newC >= 0 && newC < l && !visited[newR][newC]) {
				visited[newR][newC] = visited[curR][curC] + 1;
				q.push({ newR,newC });
			}
		}

	}
}