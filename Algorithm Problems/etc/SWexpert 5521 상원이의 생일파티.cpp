#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int N, M, ans;
bool adj[550][550], visited[550];

int bfs();

int main() {
	int T; cin >> T;
	for (int tcase = 1; tcase <= T; tcase++) {
		cin >> N >> M;
		for (int i = 0; i <= N; i++) memset(adj[i], false, sizeof(bool)*(N + 10));
		memset(visited, false, sizeof(bool) * 550);

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			adj[a][b] = adj[b][a] = true;
		}

		printf("#%d %d\n", tcase, bfs());
	}

}

int bfs() {
	queue <pair <int, int> > q;
	q.push({ 1,0 });
	visited[1] = true;
	int friends = 0;

	while (!q.empty()) {
		pair <int,int> cur = q.front();
		q.pop();
		if (cur.second > 2) break;

		for (int c = 1; c <= N; c++) {
			if (adj[cur.first][c] && !visited[c]) {
				visited[c] = true;
				q.push({ c,cur.second + 1 });
				if(cur.second+1 <=2)
					friends++;
			}
		}

	}
	return friends;
}