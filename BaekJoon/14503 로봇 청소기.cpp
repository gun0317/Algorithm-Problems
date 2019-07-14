#include <iostream>
#include <cstdio>
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define BOUNDARY nextRow>=0&&nextRow<maxR&&nextCol>=0&&nextCol<maxC
using namespace std;

typedef struct robot {
	int row, col, dir;
}robot;

robot r;
int map[55][55],cleaned[55][55];
int maxR, maxC;
int dr[] = { -1,0,1,0 }, dc[] = { 0,1,0,-1 };

// 무한루프를 유발하는 케이스?
void simul() {
	while (1) {
		int flag = 0;	// 4방향 확인했는지 check
		// 좌로 4번 까지만 돌아본다
		for (int i = 0; i < 4; i++) {
			int nextRow = r.row + dr[(r.dir + 3) % 4];
			int nextCol = r.col + dc[(r.dir + 3) % 4];
			// already cleand || a wall -> direction change
			if (BOUNDARY && (cleaned[nextRow][nextCol] == 1 || map[nextRow][nextCol] == 1)) {
				r.dir = (r.dir + 3) % 4;
				flag++;
				continue;
			}
			// need to be cleaned & move
			if (BOUNDARY && cleaned[nextRow][nextCol] == 0 && map[nextRow][nextCol] == 0) {
				r.row = nextRow;
				r.col = nextCol;
				r.dir = (r.dir + 3) % 4;
				cleaned[nextRow][nextCol] = 1;
				break;
			}
		}
		// 4 direction check, everything is cleaned or a wall
		if (flag == 4) {
			int nextRow = r.row - dr[r.dir];
			int nextCol = r.col - dc[r.dir];
			// able to go back
			if (BOUNDARY && map[nextRow][nextCol] == 0) {
				r.row = nextRow;
				r.col = nextCol;
				continue;
			}
			// unable to go back; end
			break;
		}

	}

}

int main() {;
	cin >> maxR >> maxC;
	cin >> r.row >> r.col >> r.dir;
	for (int r = 0; r < maxR; r++)
		for (int c = 0; c < maxC; c++){
			scanf(" %d", &map[r][c]);
			/*cleaned[r][c] = map[r][c];*/
		}
	cleaned[r.row][r.col] = 1;
	simul();
	int ans = 0;
	for (int r = 0; r < maxR; r++)
		for (int c = 0; c < maxC; c++) 
			if (cleaned[r][c]) ans++;
		
	cout << ans << endl;
	return 0;
}