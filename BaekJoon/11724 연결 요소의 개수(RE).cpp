#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stack>
#include <queue>
#define pair pair <int,int>
using namespace std;
int N, M, map[1001][1001], visited[1001];
queue <int> q;

void BFS() {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (!visited[i] && map[cur][i]) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	int u, v;
	for (int i = 1; i <= M; i++) {
		cin >> u >> v;
		map[u][v] = map[v][u] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			q.push(i);
			visited[i] = 1;
			BFS();
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}