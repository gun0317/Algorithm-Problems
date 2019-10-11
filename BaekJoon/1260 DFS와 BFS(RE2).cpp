#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs_rec(int cur);
void bfs(int cur);

vector <int> outdegree[1010];
int nodes_num, edge_num, startingNode, visited[1010], visited2[1010];

int main() {
	cin >> nodes_num >> edge_num >> startingNode;
	for (int i = 0; i < edge_num; i++) {
		int from, to;
		scanf(" %d %d", &to, &from);
		outdegree[from].push_back(to);
		outdegree[to].push_back(from);
	}

	for (int i = 0; i <= nodes_num; i++) 
		sort(outdegree[i].begin(), outdegree[i].end());

	dfs_rec(startingNode);
	cout << endl;
	bfs(startingNode);

	return 0;
}

void dfs_rec(int cur) {
	printf("%d ", cur);
	visited[cur]++;
	for (int traversingNode : outdegree[cur]) {
		if (!visited[traversingNode]) {
			dfs_rec(traversingNode);
		}
	}
}

void bfs(int cur) {
	queue <int> node_to_explore;
	node_to_explore.push(cur);
	visited2[cur]++;

	while (!node_to_explore.empty()) {
		int curNode = node_to_explore.front();
		node_to_explore.pop();
		printf("%d ", curNode);

		for (int traversingNode : outdegree[curNode]) {
			if (!visited2[traversingNode]) {
				visited2[traversingNode]++;
				node_to_explore.push(traversingNode);
			}
		}
	}
}