#include <iostream>
using namespace std;

int map[110][110], visited[110][110], N, order;
int dr[] = { 1,0,-1 }, dc[] = { 1,-1,0 };

void dfs(int r, int c, int dir) {
	visited[r][c] = 1;
	map[r][c] = order++;

	int newR = r + dr[dir];
	int newC = c + dc[dir];
	int no_where_to_go_cnt = 0;
	while (!(newR >= newC && map[newR][newC] == -1)) {
		dir = (dir + 1) % 3;
		newR = r + dr[dir];
		newC = c + dc[dir];
		no_where_to_go_cnt++;
		if (no_where_to_go_cnt > 4) return;
	}
	dfs(newR, newC, dir);
}


int main() {
	cin >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			map[r][c] = -1;

	dfs(0,0,0);
	
	for (int r = 0; r < N; r++) {
		for (int c = 0; c <= r; c++)
			printf("%d ", map[r][c]%10);
		cout << endl;
	}

	return 0;
}