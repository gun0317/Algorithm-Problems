#include <iostream>
#include <queue>
using namespace std;

int totalFloor, currentFloor, goalFloor, up, down, ansFlag;
int moves[2];
bool visited[1000010];
int bfs();

int main() {
	cin >> totalFloor >> currentFloor >> goalFloor >> up >> down;
	moves[0] = up, moves[1] = -down;
	ansFlag = 0;
	int ans = bfs();

	if (ansFlag == 0) cout << "use the stairs" << endl;
	else cout << ans << endl;

	return 0;
}

int bfs() {
	queue <pair<int,int> > q;
	q.push({ 0,currentFloor });
	visited[currentFloor] = true;

	while (!q.empty()) {
		pair <int,int> cur = q.front();
		q.pop();
		if (cur.second == goalFloor) {
			ansFlag = 1;
			return cur.first;
		}

		for (int i = 0; i < 2; i++) {
			int newFloor = cur.second + moves[i];
			if (newFloor <= totalFloor && newFloor >= 0 && !visited[newFloor]) {
				visited[newFloor] = true;
				q.push({ cur.first + 1,newFloor });
			}
		}
	}
}