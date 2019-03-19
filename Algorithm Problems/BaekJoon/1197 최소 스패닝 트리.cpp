#include <iostream>
#include <vector>
#include <string.h>
#define pair pair <int, int> 
using namespace std;
int V, E;
int visited[10011];
int primArr[10011];

vector <pair> *graph;

int main() {
	// getting input & initializing
	int from, to, weight;
	cin >> V >> E;
	graph = new vector <pair>[10010];


	for (int i = 1; i <= 10010; i++) primArr[i] = 1000010;
	memset(visited, 0, sizeof(int)*(V + 1));

	for (int i = 0; i < E; i++) {
		cin >> from >> to >> weight;
		graph[from].push_back(make_pair(to, weight));
		graph[to].push_back(make_pair(from, weight));
		visited[from] = -1;
		visited[to] = -1;
	}
	int lastVertex = from;

	// A variable that saves how far we've got & where we are expanding
	int connectedVertices = 1;
	int cur = lastVertex;
	primArr[cur] = 0;
	visited[cur] = 1;


	// Prim's algorithm; traversing all possible edges
	while (1) {
		// end condition
		if (connectedVertices == V) break;

		// Updating Prim's array
		while (!graph[cur].empty()) {

			// current from, to, weight
			int f = cur;
			int t = graph[cur].back().first;
			int w = graph[cur].back().second;

			if (primArr[t] > w && visited[t] == -1)
				primArr[t] = w;

			graph[cur].pop_back();
		}

		// Expanding the vertex
		int min = 1000010;
		for (int j = 1; j <= 10010; j++) {
			if (min > primArr[j] && visited[j] == -1) {
				min = primArr[j];
				cur = j;
			}
		}

		visited[cur] = 1;
		connectedVertices++;
	}

	// calculating the ans
	long long ans = 0;
	for (int i = 1; i <= 10000; i++)
		if (visited[i] == 1)
			ans += primArr[i];

	cout << ans << endl;

	delete[] graph;

	return 0;
}

/*
3 3
3 7 1
3 5 3
5 7 2

2 1
1 2 1

4 5
2 4 1
6 4 -2
7 4 -8
7 6 -3
6 2 -88

*/