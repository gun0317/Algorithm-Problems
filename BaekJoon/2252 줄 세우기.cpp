#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, indegree[33010];

int main() {
	cin >> N >> M;

	vector <int> outDegree[33010];
	vector <int> answer;

	for (int i = 0; i < M; i++) {
		int from, to;
		scanf(" %d %d", &from, &to);
		indegree[to]++;
		outDegree[from].push_back(to);
	}

	queue <int> indegree_zero;

	for (int i = 1; i <= N; i++) 
		if (indegree[i] == 0) indegree_zero.push(i);

	while (!indegree_zero.empty()) {
		int curNode = indegree_zero.front();
		indegree_zero.pop();
		answer.push_back(curNode);

		for (int traversing_node : outDegree[curNode]) {
			indegree[traversing_node]--;

			if (indegree[traversing_node] == 0) 
				indegree_zero.push(traversing_node);
		}
	}

	for (int ans : answer) cout << ans << " ";
	cout << endl;

	return 0;
}