//#include <iostream>
//using namespace std;
//int adj[1010][1010];
//int cnt = 0, N, M, visited[1010];
//
//void DFS(int node) {
//	visited[node] = 1;
//	for (int i = 1; i <= N; i++)
//		if (!visited[i] && adj[node][i])
//			DFS(i);
//}
//
//int main() {
//	int u, v;
//	cin >> N >> M;
//	for (int i = 1; i <= M; i++) {
//		cin >> u >> v;
//		adj[u][v] = 1;
//		adj[v][u] = 1;
//	}
//
//	for (int i = 1; i <= N; i++)
//		if (!visited[i]){
//			cnt++;
//			DFS(i);
//		}
//	cout << cnt;
//
//	return 0;
//}