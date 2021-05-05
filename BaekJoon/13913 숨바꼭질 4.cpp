#include <iostream>
#include <queue> 
using namespace std;
int visited[100010], path[100010];
int start, dest, time;

void BFS() {
	for (int i = 0; i < 100010; i++) 
		visited[i] = -2;
	queue <int> q;
	q.push(start);
	visited[start] = -1;
	int newCur[3], flag = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		newCur[0] = cur - 1;
		newCur[1] = cur + 1;
		newCur[2] = cur * 2;
		
		for (int i = 0; i < 3; i++) {
			if (newCur[i] >= 0 && newCur[i] < 100001) {
				if (visited[newCur[i]] == -2) {
					visited[newCur[i]] = cur;	//���� ��ġ�� ���� for ���
					if (newCur[i] == dest) {
						flag = 1; break;
					}
					q.push(newCur[i]);
				}
			}
		}
		
		if (flag == 1) break;
	}
}

void Path() {
	int idx = dest;
	int pathIdx = 0;
	while (visited[idx] != -1) {
		path[pathIdx++] = idx;
		idx = visited[idx]; 
		time++;
	}
	path[pathIdx++] = start;
	cout << time << endl;
	for (int i = pathIdx - 1; i >= 0; i--)
		cout << path[i] << " ";
	cout << endl;
}

int main() {
	cin >> start >> dest;
	if (start == dest) {
		cout << 0 << endl;
		cout << start;
		return 0;
	}
	BFS();
	Path();

	return 0;
}