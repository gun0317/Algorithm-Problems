#include <string>
#include <vector>
#include <queue>
using namespace std;
bool visited[300];
int answer;

void bfs(int n, int start, vector <vector <int> > computers) {
	answer++;
	queue <int> com;
	visited[start] = true;
	com.push(start);
	while (!com.empty()) {
		int curNode = com.front();
		com.pop();
		for (int out = 0; out < n; out++) {
			if (out != curNode && computers[curNode][out] == 1 && !visited[out]) {
				visited[out]++;
				com.push(out);
			}
		}
	}
}

int solution(int n, vector <vector <int> > computers) {
	for (int i = 0; i < n; i++) 
		if(!visited[i]) bfs(n, i, computers);

	return answer;
}