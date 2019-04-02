#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int map[510][510], visited[510][510];
int N, M, ans;
void back(int depth, int curR, int curC);
void calculate();
bool validity(int r, int c, int visited[510][510]);
int dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 };
vector <pair <int, int>> v;

int main() {
	cin >> N >> M;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			scanf(" %d", &map[r][c]);

	back(0, 0, 0);
	cout << ans << endl;
	return 0;
}

void calculate() {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += map[v[i].first][v[i].second];
	}

	if (sum > ans) ans = sum;
}

// 인접 블록이 있는지 검색
// 상 하 좌 우에 대하여 한 번이라도 인접 블록이 등장하면 true
bool validity(int r, int c, int visited[510][510]) {
	for (int i = 0; i < 4; i++) {
		// boundary check
		if (r + dr[i] >= 0 && r + dr[i] < N&&c + dc[i] >= 0 && c + dc[i] < M) {
			if (visited[r + dr[i]][c + dc[i]] == 1) return true;
		}
	}
	return false;
}

void back(int depth, int curR, int curC) {
	int maxR = curR + 4;
	int maxC = curC + 4;
	int minC = curC - 4;
	if (minC < 0) minC = 0;

	if (depth == 4) {
		calculate();
		return;
	}

	else {
		if (depth == 0) {
			for (int r = 0; r < N; r++) {
				for (int c = 0; c < M; c++) {
					// depth가 0인 경우는 주변에 블록이 없어도 배치 가능해야함
					visited[r][c] = 1;
					v.push_back(make_pair(r, c));
					back(depth + 1, r, c);
					visited[r][c] = 3; // 시작점이 반복되지 않게 0이 아닌 값을 표시
					v.pop_back();
					// 시작점이 한 번이라도 들어가면 그 이후론 고려하지 않아도 됨
				}
			}
		}

		// depth가 1 이상이면 주변에 블록이 있어야만 배치 (validity이용)
		// cur는 0부터가야함
		// row는 0부터 가면 중복 발생 -> 전달받은 현재 row로 진행
		else if (depth > 0) {
			for (; curR < maxR; curR++) {
				for (int c = minC; c < maxC; c++) {
					if (visited[curR][c] == 0 && validity(curR, c, visited)) {
						visited[curR][c] = 1;
						v.push_back(make_pair(curR, c));
						back(depth + 1, curR, c);
						visited[curR][c] = 0;
						v.pop_back();
					}
				}
			}
		}
	}
}