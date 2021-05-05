#include <iostream>
#include <queue>
using namespace std;
int arr[1010][1010];
int visited[1010];
int N, M, u, v,cnt;

void BFS()
{
	queue <int> q;
	if (!visited[1])
	{
		q.push(1);
		visited[1] = 1;
	}
	else
	{
		for (int i = 2; i <= N; i++) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = 1;
				break;
			}
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 2; i <= N; i++) {
			if (!visited[i] && arr[cur][i])
			{
				visited[i] = 1;
				q.push(i);
			}
		}

	}
	cnt++;

	//do BFS again if there is unvisited vtx
	for (int i = 1; i <= N; i++)
		if (!visited[i])
			BFS();
	
}

int main()
{
	cin >> N >> M;
	//completing adjacency matrix
	for (int i = 1; i <= M; i++) {
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}
	BFS();
	cout << cnt << endl;

	return 0;
}