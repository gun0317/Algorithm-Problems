#include <iostream>
using namespace std;
int N, synergy[30][30], visited[30], ans;

void back(int depth, int cur);


int main() {
	cin >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> synergy[r][c];

	ans = 999999999;
	back(0, 0);
	cout << ans << endl;

	return 0;
}

void back(int depth, int cur) {
	if (depth == N / 2) {
		// team1
		int team1 = 0;
		for (int i = 0; i < N; i++) {
			if (visited[i]) {
				for (int r = i + 1; r < N; r++) {
					if (visited[r]) {
						team1 += synergy[i][r];
						team1 += synergy[r][i];
					}
				}
			}
		}
		// team2
		int team2 = 0;
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				for (int r = i + 1; r < N; r++) {
					if (!visited[r]) {
						team2 += synergy[i][r];
						team2 += synergy[r][i];
					}
				}
			}
		}

		if (ans > abs(team2 - team1)) ans = abs(team2 - team1);

		return;
	}
	else {
		for (; cur < N; cur++) {
			if (!visited[cur]) {
				visited[cur] = 1;
				back(depth + 1, cur+1);
				visited[cur] = 0;
			}
		}
	}
}