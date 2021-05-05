#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stack>
#include <queue>
#include <string.h> // test case�� memset���
#define pair pair <int,int>
using namespace std;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int N, M, V, map[1001][1001], visited[1001];

void BFS(int vtx) {
	queue <int> q;
	q.push(vtx);
	visited[vtx] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 1; i <= N; i++) 
			if (!visited[i] && map[cur][i]) {
				visited[i] = 1;
				q.push(i);
			}
	}

}

void DFS(int vtx) {
	visited[vtx] = 1;
	cout << vtx << " ";
	for (int i = 1; i <= N; i++)
		if (!visited[i] && map[vtx][i])
			DFS(i);
	
}

int main() {
	cin >> N >> M >> V;
	int u, v;
	for (int i = 1; i <= M; i++) {
		cin >> u >> v;
		map[u][v] = map[v][u] = 1;
	}
	
	DFS(V);
	cout << endl;
	for(int i=0;i<N;i++)
		memset(visited, 0, sizeof(visited));
	BFS(V);




	return 0;
}