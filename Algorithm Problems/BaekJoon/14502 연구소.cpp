#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int maxR, maxC, map[10][10], ans, virusCnt;
int dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 };
vector <pair <int, int>> v;

void back(int depth, int curR);
void spread();

int main() {
	cin >> maxR >> maxC;
	for (int r = 0; r < maxR; r++)
		for (int c = 0; c < maxC; c++) {
			cin >> map[r][c];
			if (map[r][c] == 2) {
				virusCnt++;
				v.push_back(make_pair(r, c));
			}
		}

	back(0, 0);

	cout << ans << endl;

	return 0;
}

void spread() {
	queue <pair <int, int>> q;
	vector <pair <int, int>> temp;
	// push the given virus
	for (int i = 0; i < virusCnt; i++)
		q.push(v[i]);

	while (!q.empty()) {
		pair <int,int> cur = q.front();
		q.pop();

		// move UP, DOWN, LEFT, RIGHT
		for (int i = 0; i < 4; i++) {
			int newR = cur.first + dr[i];
			int newC = cur.second + dc[i];

			// boundary check & map[newR][newC]=0 check
			if (newR < maxR && newR >= 0 && newC < maxC && newC >= 0 && map[newR][newC] == 0) {
				q.push(make_pair(newR, newC));
				map[newR][newC] = 2;
				temp.push_back(make_pair(newR, newC));
			}
		}
		
	}
	
	// calculate the area of 0s
	int zeros = 0;
	for (int r = 0; r < maxR; r++)
		for (int c = 0; c < maxC; c++)
			if (map[r][c] == 0) zeros++;
	if (ans < zeros) ans = zeros;

	// unspread the virus
	for (int i = 0; i < temp.size(); i++)
		map[temp[i].first][temp[i].second] = 0;
}

void back(int depth, int curR) {
	if (depth == 3) {
		spread();
		return;
	}
	else {
		for (; curR < maxR; curR++)
			for (int c = 0; c < maxC; c++) {
				if (map[curR][c] == 0) {
					map[curR][c] = 1;
					back(depth + 1, curR);
					map[curR][c] = 0;
				}
			}
	}
}