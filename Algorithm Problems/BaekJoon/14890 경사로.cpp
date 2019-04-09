#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int N, L, ans, map[110][110], visited[110][110];
void check();

int main() {
	cin >> N >> L;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			scanf(" %d", &map[r][c]);

	check();
	cout << ans << endl;

	return 0;
}

void check() {
	// Rows check
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N - 1; c++) {
			int endFlag = 0;
			// impossible case
			if (abs(map[r][c] - map[r][c + 1]) > 1)break;
			// current is higher
			if (map[r][c] - map[r][c + 1] == 1) {
				for (int i = 0; i < L; i++) {
					if (c + 1 + i < N && map[r][c + 1 + i] == map[r][c + 1] && visited[r][c + 1 + i] == 0) {
						visited[r][c + 1 + i] = 1;
						continue;
					}
					else {
						endFlag++;
						break;
					}
				}
				if (endFlag > 0) break;
			}
			// next is higher
			if (map[r][c + 1] - map[r][c] == 1) {
				for (int i = 0; i < L; i++) {
					if (c - i >= 0 && map[r][c - i] == map[r][c] && visited[r][c - i] == 0) {
						visited[r][c - i] = 1;
						continue;
					}
					else {
						endFlag++;
						break;
					}
				}
				if (endFlag > 0)break;
			}
			// survived!
			if (c == N - 2) {
				//cout << "success at row: " << r << endl;
				ans++;
			}
		}
	//visited re-initialization
	for (int i = 0; i < N; i++)
		memset(visited[i], 0, sizeof(int)*N);
	// Cols check
	for (int c = 0; c < N; c++)
		for (int r = 0; r < N - 1; r++) {
			int endFlag = 0;
			// impossible case
			if (abs(map[r][c] - map[r + 1][c]) > 1) break;
			// current is higher
			if (map[r][c] - map[r + 1][c] == 1) {
				for (int i = 0; i < L; i++) {
					if (r + 1 + i < N && map[r + 1 + i][c] == map[r + 1][c] && visited[r + 1 + i][c] == 0) {
						visited[r + 1 + i][c] = 1;
						continue;
					}
					else {
						endFlag++;
						break;
					}
				}
				if (endFlag > 0) break;
			}
			// next is higher
			if (map[r + 1][c] - map[r][c] == 1) {
				for (int i = 0; i < L; i++) {
					if (r - i >= 0 && map[r - i][c] == map[r][c] && visited[r - i][c] == 0) {
						visited[r - i][c] = 1;
						continue;
					}
					else {
						endFlag++;
						break;
					}
				}
				if (endFlag > 0)break;
			}
			// survived!
			if (r == N - 2) {
				//cout << "success at col: " << c << endl;
				ans++;
			}
		}
}