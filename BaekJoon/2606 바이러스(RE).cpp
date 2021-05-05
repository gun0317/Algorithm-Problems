#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stack>
#include <queue>
#define pair pair <int,int>
using namespace std;
int N, M, map[1001][1001], visited[1001];
int cnt = 0;

void DFS(int cur) {
	visited[cur] = 1;
	for (int i = 1; i <= N; i++)
		if (!visited[i] && map[cur][i])
			DFS(i);
	cnt++;
}

int main() {
	cin >> N >> M; int u, v;
	for (int i = 1; i <= M; i++) {
		cin >> u >> v;
		map[u][v] = map[v][u] = 1;
	}
	DFS(1);
	cout << cnt-1;

	return 0;
}