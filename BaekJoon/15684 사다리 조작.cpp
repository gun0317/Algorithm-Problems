#include <iostream>
using namespace std;
void back(int addWhat, int depth, int row, int col);
bool check();
int N, M, H, map[30][50], flag;
// N<=10, H<=30, M<300

int main(void) {
	cin >> N >> M >> H;
	for (int i = 1; i <= M; i++) {
		int a, b;	//b와 b+1을 a행에서 잇는다
		cin >> a >> b;
		map[a][b] = 1;
		map[a][b + 1] = 2;
	}

	for (int i = 0; i <= 3; i++) {
		back(i, 0, 1, 1);
		if (flag > 0)
		{
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}


void back(int addWhat, int depth, int row, int col) {
	// end condition
	if (depth == addWhat) {
		if (check())
		{
			flag++;
			cout << addWhat << endl;
		}
		return;
	}
	// new combination
	else {
		for (row; row <= H; row++) {
			for (int c = 1; c < N; c++) {
				if (map[row][c] == 0 && map[row][c + 1] == 0) {
					map[row][c] = 1;
					map[row][c + 1] = 2;
					if (flag > 0) return;
					back(addWhat, depth + 1, row, col);
					map[row][c] = map[row][c + 1] = 0;
					if (flag > 0) return;
				}
			}
		}
	}
}

bool check() {
	// traverse through the ladder
	for (int c = 1; c <= N; c++) {
		int cur = c;
		for (int r = 1; r <= H; r++) {
			if (map[r][cur] == 1) cur += 1;
			else if (map[r][cur] == 2) 	cur -= 1;
		}
		if (cur != c) return false;
	}
	return true;
}