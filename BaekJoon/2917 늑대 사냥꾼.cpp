#include <iostream>
using namespace std;

typedef struct point {
	int row, col;
}point;

typedef struct my_queue {
	point q[2500000];
	int rear = -1, front = -1;
	
	int isEmpty() {
		return (rear == front) ? 1 : 0;
	}

	void push(int r, int c) {
		point temp;
		temp.row = r, temp.col = c;
		q[++rear] = temp;
	}

	point pop() {
		if (!isEmpty()) return q[++front];
	}
}my_queue;

my_queue dist_queue, visit_queue;
int dist[550][550], visited[550][550];
int startR, startC, goalR, goalC, maxR, maxC;
int dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 }, maximum = 0xfffffff;

void bfs(int r,int c, int target) {
	visit_queue.push(r, c);
	visited[r][c] = 1;
	if (dist[r][c] < target) return;
	while (!visit_queue.isEmpty()) {
		point cur = visit_queue.pop();
		int curR = cur.row;
		int curC = cur.col;
		for (int i = 0; i < 4; i++) {
			int newR = curR + dr[i];
			int newC = curC + dc[i];
			if (!(newR < maxR&&newR >= 0 && newC >= 0 && newC < maxC))
				continue;
			if (visited[newR][newC]) continue;
			if (dist[newR][newC] >= target) {
				visited[newR][newC] = 1;
				visit_queue.push(newR, newC);
			}
		}
	}
}

int localMax = 0;
void updateDist() {
	while (!dist_queue.isEmpty()) {
		point cur = dist_queue.pop();
		int curR = cur.row;
		int curC = cur.col;
 		for (int i = 0; i < 4; i++) {
			int newR = curR + dr[i];
			int newC = curC + dc[i];
			if (!(newR < maxR&&newR >= 0 && newC >= 0 && newC < maxC))
				continue;
			if (dist[newR][newC] > dist[curR][curC] + 1) {
				dist[newR][newC] = dist[curR][curC] + 1;
				dist_queue.push(newR, newC);
				if (dist[newR][newC] > localMax) 
					localMax = dist[newR][newC];
			}
		}
	}
}

int main() {
	cin >> maxR >> maxC;
	for (int r = 0; r < maxR; r++) {
		for (int c = 0; c < maxC; c++) {
			char temp;
			scanf(" %1c", &temp);
			switch (temp)
			{
			case '+': 
				dist_queue.push(r, c);
				dist[r][c] = 0;
				break;
			case 'V': 
				dist[r][c] = maximum;
				startR = r, startC = c;
				break;
			case 'J':
				dist[r][c] = maximum;
				goalR = r, goalC = c;
				break;
			default:
				dist[r][c] = maximum;
				break;
			}
		}
	}

	updateDist();
	int left = 0, right = localMax, ans = -1;
	while (left <= right) {
		for (int r = 0; r < 550; r++)
			for (int c = 0; c < 550; c++) visited[r][c] = 0;
		int mid = (left + right) / 2;
		if (ans > mid) break;
		bfs(startR, startC, mid);
		if (visited[goalR][goalC]) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << ans << endl;

	return 0;
}