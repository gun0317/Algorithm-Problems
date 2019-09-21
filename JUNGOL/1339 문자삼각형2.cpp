#include <iostream>
using namespace std;

int map[110][110];

int main() {
	int N; cin >> N;

	char toPrint = 'A';
	for (int col = (N - 1) / 2; col >= 0; col--) {
		for (int row = col; row <= (N/2)*2 - col; row++) {
			if (toPrint > 'Z') toPrint = 'A';
			map[row][col] = toPrint++;
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) printf("%c ", map[r][c]);
		cout << endl;
	}


	return 0;
}