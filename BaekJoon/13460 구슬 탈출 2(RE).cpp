#include <iostream>
#include <queue>
#define BOUNDARY row<maxRow-1 && row>=1 && col<maxCol-1 && col>=1
using namespace std;
typedef struct Balls_ {
	int blueRow, blueCol, redRow, redCol, depth;
}Balls;
Balls initBalls;
int maxCol, maxRow, holeRow, holeCol, ans = -1;
int dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 };
char map[12][12];
bool visited[12][12][12][12];	//Red r,c Blue r,c Order

void BFS();
void go(int &row, int &col, int dir);

int main() {
	initBalls.depth = 0;
	cin >> maxRow >> maxCol;
	for (int r = 0; r < maxRow; r++)
		for (int c = 0; c < maxCol; c++) {
			cin >> map[r][c];
			if (map[r][c] == 'B') {
				initBalls.blueRow = r;
				initBalls.blueCol = c;
			}
			else if (map[r][c] == 'R') {
				initBalls.redRow = r;
				initBalls.redCol = c;
			}
			else if (map[r][c] == 'O') {
				holeRow = r;
				holeCol = c;
			}
		}
	visited[initBalls.redRow][initBalls.redCol][initBalls.blueRow][initBalls.blueCol] = true;
	BFS();
	cout << ans << endl;

	return 0;
}

void BFS() {
	queue <Balls> q;
	q.push(initBalls);

	while (!q.empty()) {
		Balls cur = q.front();
		q.pop();
		if (cur.depth > 10) {
			ans = -1;
			return;
		}
		if (cur.redRow == holeRow && cur.redCol == holeCol) {
			ans = cur.depth;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int newRedRow = cur.redRow, newRedCol = cur.redCol;
			int newBlueRow = cur.blueRow, newBlueCol = cur.blueCol;
			go(newRedRow, newRedCol, i); go(newBlueRow, newBlueCol, i);

			if (newBlueRow == holeRow && newBlueCol == holeCol) continue;
			if (newBlueRow == newRedRow && newBlueCol == newRedCol) {
				switch (i) {
				case 0: // UP
					if (cur.blueRow > cur.redRow) newBlueRow++;
					else newRedRow++;
					break;
				case 1: // DOWN
					if (cur.blueRow > cur.redRow) newRedRow--;
					else newBlueRow--;
					break;
				case 2: // LEFT
					if (cur.blueCol > cur.redCol) newBlueCol++;
					else newRedCol++;
					break;
				case 3: // RIGHT
					if (cur.blueCol > cur.redCol) newRedCol--;
					else newBlueCol--;
					break;
				}
			}
			if (!visited[newRedRow][newRedCol][newBlueRow][newBlueCol]) {
				visited[newRedRow][newRedCol][newBlueRow][newBlueCol] = 1;
				Balls temp;
				temp.blueCol = newBlueCol, temp.blueRow = newBlueRow;
				temp.redCol = newRedCol, temp.redRow = newRedRow;
				temp.depth = cur.depth + 1;
				q.push(temp);
			}

		}
	}
}

void go(int &row, int &col, int dir) {
	while (true) {
		row += dr[dir]; col += dc[dir];
		if (map[row][col] == '#') {
			row -= dr[dir]; col -= dc[dir];
			return;
		}
		else if (map[row][col] == 'O')
			return;
	}
}