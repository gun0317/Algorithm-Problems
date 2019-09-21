#include <iostream>
using namespace std;

char map[110][110], toPrint = 'A';
int N, intmap[110][110];

int main() {
	cin >> N;
	for (int r = 0; r < N; r++)
		for (int localR = r, k = N; localR < N; localR++,k--) {
			if (toPrint > 'Z') toPrint = 'A';
			map[localR][k] = toPrint++;
		}

	for (int r = 0; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (map[r][c] == 0) printf("  ");
			else printf("%c ", map[r][c]);
		}
		printf("\n");
	}

	return 0;
}