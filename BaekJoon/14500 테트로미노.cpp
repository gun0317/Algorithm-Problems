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

// ���� ����� �ִ��� �˻�
// �� �� �� �쿡 ���Ͽ� �� ���̶� ���� ����� �����ϸ� true
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
					// depth�� 0�� ���� �ֺ��� ����� ��� ��ġ �����ؾ���
					visited[r][c] = 1;
					v.push_back(make_pair(r, c));
					back(depth + 1, r, c);
					visited[r][c] = 3; // �������� �ݺ����� �ʰ� 0�� �ƴ� ���� ǥ��
					v.pop_back();
					// �������� �� ���̶� ���� �� ���ķ� ������� �ʾƵ� ��
				}
			}
		}

		// depth�� 1 �̻��̸� �ֺ��� ����� �־�߸� ��ġ (validity�̿�)
		// cur�� 0���Ͱ�����
		// row�� 0���� ���� �ߺ� �߻� -> ���޹��� ���� row�� ����
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