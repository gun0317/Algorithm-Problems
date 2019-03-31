#include <iostream>
#define TOP 0
#define BOT 1
#define NORTH 2
#define EAST 3
#define WEST 4
#define SOUTH 5
using namespace std;
int map[22][22];
int N, M, x, y, k;
int dice[6];
void move(int order, int &curR, int &curC);

int main() {
	cin >> N >> M >> x >> y >> k;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> map[r][c];
	int curR = x, curC = y, order = 999;
	for (int i = 0; i < k; i++) {
		cin >> order;
		move(order, curR, curC);
	}

	return 0;
}

void move(int order, int &curR, int &curC) {
	switch (order)
	{
	case 1:	// RIGHT
		if (curC + 1 < M) {
			curC++;
			int temp = dice[TOP];
			dice[TOP] = dice[WEST];
			dice[WEST] = dice[BOT];
			dice[BOT] = dice[EAST];
			dice[EAST] = temp;
			cout << dice[TOP] << endl;
			if (map[curR][curC] == 0) map[curR][curC] = dice[BOT];
			else {
				dice[BOT] = map[curR][curC];
				map[curR][curC] = 0;
			}
		}
		break;
	case 2:	// LEFT
		if (curC - 1 >= 0) {
			curC--;
			int temp = dice[TOP];
			dice[TOP] = dice[EAST];
			dice[EAST] = dice[BOT];
			dice[BOT] = dice[WEST];
			dice[WEST] = temp;
			cout << dice[TOP] << endl;
			if (map[curR][curC] == 0) map[curR][curC] = dice[BOT];
			else {
				dice[BOT] = map[curR][curC];
				map[curR][curC] = 0;
			}
		}
		break;
	case 3: // UP
		if (curR - 1 >= 0) {
			curR--;
			int temp = dice[TOP];
			dice[TOP] = dice[SOUTH];
			dice[SOUTH] = dice[BOT];
			dice[BOT] = dice[NORTH];
			dice[NORTH] = temp;
			cout << dice[TOP] << endl;
			if (map[curR][curC] == 0) map[curR][curC] = dice[BOT];
			else {
				dice[BOT] = map[curR][curC];
				map[curR][curC] = 0;
			}
		}
		break;
	case 4: // DOWN
		if (curR + 1 < N) {
			curR++;
			int temp = dice[BOT];
			dice[BOT] = dice[SOUTH];
			dice[SOUTH] = dice[TOP];
			dice[TOP] = dice[NORTH];
			dice[NORTH] = temp;
			cout << dice[TOP] << endl;
			if (map[curR][curC] == 0) map[curR][curC] = dice[BOT];
			else {
				dice[BOT] = map[curR][curC];
				map[curR][curC] = 0;
			}
		}
		break;
	default:
		break;
	}
}