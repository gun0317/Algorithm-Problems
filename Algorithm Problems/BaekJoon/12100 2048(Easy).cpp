#include <iostream>
#include <string.h>
using namespace std;
int N, map[22][22], localMap[22][22], localArr[22][22], path[6], ans;

void copy() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			localMap[r][c] = map[r][c];
}
int calculate() {
	int localVal = 0;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++) {
			if (localVal < localMap[r][c])
				localVal = localMap[r][c];
			if (localVal == 32)
				;
		}
	return localVal;
}
void move() {
	for (int i = 0; i < 5; i++) {
		int dir = path[i];
		switch (dir)
		{
		case 1:	// UP
			for (int c = 0; c < N; c++) {
				int idx = 0;
				for (int r = 0; r < N; r++) if (localMap[r][c] > 0)	localArr[idx++][c] = localMap[r][c];
			}

			for (int c = 0; c < N; c++) {

				// Adding
				int i;
				for (i = 0; i < N; i++)
					if (localArr[i][c] > 0 && i + 1 < N && localArr[i][c] == localArr[i + 1][c]) {
						localArr[i][c] *= 2;
						localArr[i + 1][c] = 0;
						i++;
					}
			}
			for (int i = 0; i < N; i++) memset(localMap[i], 0, sizeof(int)*N);

			// Copying the valid blocks to the local Arr
			for (int c = 0; c < N; c++) {
				int idx = 0;
				for (int r = 0; r < N; r++)
					if (localArr[r][c] > 0)
						localMap[idx++][c] = localArr[r][c];
			}

			for (int i = 0; i < N; i++) memset(localArr[i], 0, sizeof(int)*N);
			break;
		case 2: // DOWN
			for (int c = N - 1; c >= 0; c--) {
				int idx = N - 1;
				for (int r = N - 1; r >= 0; r--)
					if (localMap[r][c] > 0)	localArr[idx--][c] = localMap[r][c];
			}
			for (int c = N - 1; c >= 0; c--) {

				// Adding
				int i;
				for (i = N - 1; i >= 0; i--)
					if (localArr[i][c] > 0 && i - 1 >= 0 && localArr[i][c] == localArr[i - 1][c]) {
						localArr[i][c] *= 2;
						localArr[i - 1][c] = 0;
						i--;
					}
			}
			for (int i = 0; i < N; i++) memset(localMap[i], 0, sizeof(int)*N);

			// Copying the valid blocks to the local Arr
			for (int c = N - 1; c >= 0; c--) {
				int idx = N - 1;
				for (int r = N - 1; r >= 0; r--)
					if (localArr[r][c] > 0)
						localMap[idx--][c] = localArr[r][c];
			}
			for (int i = 0; i < N; i++) memset(localArr[i], 0, sizeof(int)*N);
			break;
		case 3: // LEFT
			for (int r = 0; r < N; r++) {
				int idx = 0;
				for (int c = 0; c < N; c++) if (localMap[r][c] > 0)	localArr[r][idx++] = localMap[r][c];
			}
			for (int r = 0; r < N; r++) {
				// Adding
				int i;
				for (i = 0; i < N; i++)
					if (localArr[r][i] > 0 && i + 1 < N && localArr[r][i] == localArr[r][i + 1]) {
						localArr[r][i] *= 2;
						localArr[r][i + 1] = 0;
						i++;
					}
			}
			for (int i = 0; i < N; i++) memset(localMap[i], 0, sizeof(int)*N);

			// Copying the valid blocks to the local Arr
			for (int r = 0; r < N; r++) {
				int idx = 0;
				for (int c = 0; c < N; c++)
					if (localArr[r][c] > 0)
						localMap[r][idx++] = localArr[r][c];
			}

			for (int i = 0; i < N; i++) memset(localArr[i], 0, sizeof(int)*N);
			break;
		case 4: // RIGHT
			for (int r = N - 1; r >= 0; r--) {
				int idx = N - 1;
				for (int c = N - 1; c >= 0; c--)
					if (localMap[r][c] > 0)	localArr[r][idx--] = localMap[r][c];

			}
			for (int r = N - 1; r >= 0; r--) {

				// Adding
				int i;
				for (i = N - 1; i >= 0; i--)
					if (localArr[r][i] > 0 && i - 1 >= 0 && localArr[r][i] == localArr[r][i - 1]) {
						localArr[r][i] *= 2;
						localArr[r][i - 1] = 0;
						i--;
					}
			}
			for (int i = 0; i < N; i++) memset(localMap[i], 0, sizeof(int)*N);

			// Copying the valid blocks to the local Arr
			for (int r = N - 1; r >= 0; r--) {
				int idx = N - 1;
				for (int c = N - 1; c >= 0; c--)
					if (localArr[r][c] > 0)
						localMap[r][idx--] = localArr[r][c];
			}
			for (int i = 0; i < N; i++) memset(localArr[i], 0, sizeof(int)*N);
			break;
		}


	}
}

void dfs(int depth, int cur, int prev) {
	if (depth == 5) {
		copy();
		move();
		int localMax = calculate();
		if (localMax > ans) ans = localMax;
	}
	else {
		for (int i = 1; i <= 4; i++) {
			if (path[cur] == 0 && i != prev) {
				path[cur] = i;
				dfs(depth + 1, cur + 1, i);
				path[cur] = 0;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> map[r][c];

	dfs(0, 0, 0);
	cout << ans << endl;


	return 0;
}