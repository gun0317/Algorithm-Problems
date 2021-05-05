#include <iostream>
using namespace std;
int adj[200][200], visited[200], cnt = -1;
int N, M, u, v;

void DFS(int vtx) {
	visited[vtx] = 1;
	for (int i = 1; i <= N; i++)
		if (!visited[i] && adj[vtx][i])
			DFS(i);
	cnt++;
}

int main() {
	int i;
	cin >> N >> M;
	for (i = 1; i <= M; i++) {
		cin >> u >> v;
		adj[u][v] = adj[v][u] = 1;
	}

	DFS(1);
	cout << cnt;

	return 0;
}