#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#define boundary newR < N&&newC < N&&newR >= 0 && newC >= 0 
using namespace std;

typedef struct shark {
	int size, eaten, movedTime, row, col;
}shark_;

typedef struct node {
	int row, col, depth, pathLength;
	bool onTheFish;
}node_;

shark_ shark;
vector <pair <int, int>> v;
int N, map[22][22], visited[22][22];
int dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 };
bool endFlag = false;

node BFS();
bool compare(node a, node b);
void go(node to);

int main() {
	shark.eaten = shark.movedTime = 0;
	shark.size = 2;
	cin >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
			if (map[r][c] == 9) {
				shark.row = r; 
				shark.col = c;
			}
		}

	while (1) {
		node to = BFS();
		if (endFlag) break;
		go(to);

	}
	cout << shark.movedTime << endl;

	return 0;
}

void go(node to) {
	if (shark.size == ++shark.eaten) {
		shark.size++;
		shark.eaten = 0;
	}

	map[shark.row][shark.col] = 0;
	map[to.row][to.col] = 9;

	shark.row = to.row;
	shark.col = to.col;
	shark.movedTime += to.pathLength;

}

node BFS() {
	int maxDepth = 99999;
	vector <node> candidates;
	queue <node> q;
	node temp;
	temp.row = shark.row; temp.col = shark.col; temp.depth = 0, temp.pathLength = 0;
	temp.onTheFish = false;
	q.push(temp);
	for (int i = 0; i < N; i++) memset(visited[i], 0, sizeof(int)*N);
	visited[temp.row][temp.col] = 1;
	
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		if (cur.depth == maxDepth && cur.onTheFish == true) {
			candidates.push_back(cur);
			continue;
		}
		else if (cur.depth == maxDepth && cur.onTheFish == false) continue;
		if (maxDepth < cur.depth) break;
		
		for (int i = 0; i < 4; i++) {
			int newR = cur.row + dr[i];
			int newC = cur.col + dc[i];

			if (boundary && visited[newR][newC] == 0 && shark.size>=map[newR][newC]) {
				visited[newR][newC] = 1;
				node temp;
				temp.row = newR; temp.col = newC; temp.depth = cur.depth + 1,temp.pathLength = cur.pathLength+1;
				if (map[newR][newC] > 0 && shark.size > map[newR][newC]) { // stepping over the fish
					temp.onTheFish = true;
					maxDepth = cur.depth + 1;
				}
				else
					temp.onTheFish = false;
		
				q.push(temp);
			}
		}
	}

	if (candidates.size() == 0) {
		endFlag = true;
		node temp;
		temp.col = 0, temp.row = 0, temp.depth = 0, temp.onTheFish = false, temp.pathLength = 0;
		return temp;
	}
	
	sort(candidates.begin(), candidates.end(),compare);
	
	return candidates[0];
}

bool compare(node a, node b) {
	if (a.row == b.row)
		return a.col < b.col;
	else
		return a.row < b.row;
}