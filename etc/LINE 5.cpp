#define _CRT_SECURE_NO_WARNINGS
#define BOUNDARY newR<=maxR && newC<=maxC && newR>=0 && newC>=0
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int map[25][25], visited[25][25], ways[25][25], time_taken[60], maxR, maxC, connieR, connieC;
int dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 };

void bfs() {
	queue <pair <int, int>> q;
	q.push({ 0,0 });
	map[0][0] = 1;
	visited[0][0] = 1;

	while (!q.empty()) {
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newR = curR + dr[i];
			int newC = curC + dc[i];

			if (BOUNDARY && !visited[newR][newC] && !map[newR][newC]) {
				visited[newR][newC] = 1;
				map[newR][newC] = map[curR][curC] + 1;
				q.push({ newR,newC });
			}
		}
	}
}

int main() {
	cin >> maxR >> maxC >> connieR >> connieC;
	if (connieR > maxR || connieC > maxC || connieR < 0 || connieC < 0) {
		cout << "fail" << endl;
		return 0;
	}
	bfs();
	cout << map[connieR][connieC] - 1 << endl;
	
	// ways!
	for (int i = 1; i <= connieC; i++) ways[0][i] = 1;
	for (int i = 1; i <= connieR; i++) ways[i][0] = 1;
	for (int r = 1; r <= connieR; r++) 
		for (int c = 1; c <= connieC; c++) 
			ways[r][c] = ways[r - 1][c] + ways[r][c - 1];

	cout << ways[connieR][connieC] << endl;

	return 0;
}