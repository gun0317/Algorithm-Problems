#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
typedef struct node {
	int depth, rR, rC, bR, bC;
}balls;

int N, M, redRow, redCol, blueRow, blueCol, goalRow, goalCol, visited[11][11][11][11];
int dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 };
char map[11][11];

void go(int i, int &row, int &col);
int bfs();

int main() {
	// getting input
	scanf("%d %d", &N, &M);
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			char input;
			scanf(" %c", &input);

			switch (input)
			{
			case '#':
				map[r][c] = '#'; break;
			case '.':
				map[r][c] = '.'; break;
			case 'R':
				map[r][c] = 'R';
				redRow = r; redCol = c;
				break;
			case 'B':
				map[r][c] = 'B';
				blueRow = r; blueCol = c;
				break;
			case 'O':
				map[r][c] = 'O';
				goalRow = r; goalCol = c;
				break;
			default:
				break;
			}
		}
	}

	cout << bfs() << endl;

	return 0;
}

void go(int i, int &row, int &col) {
	while (1) {
		row += dr[i], col += dc[i];
		if (map[row][col] == '#') {			// stops when the ball faces the wall(move back)
			row -= dr[i], col -= dc[i];
			break;
		}
		if (map[row][col] == 'O') break;	// stops when the ball is in the hole
	}

}

int bfs() {
	queue <balls> q;
	balls init;
	init.bR = blueRow; init.bC = blueCol; init.rR = redRow; init.rC = redCol, init.depth = 0;
	visited[redRow][redCol][blueRow][blueCol] = 1;
	q.push(init);
	int ans = -1;

	while (!q.empty()) {
		balls cur = q.front();
		q.pop();
		if (cur.depth > 10) break;
		if (cur.rR == goalRow && cur.rC == goalCol) {
			ans = cur.depth;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int RR = cur.rR, RC = cur.rC, BR = cur.bR, BC = cur.bC;
			go(i, RR, RC); go(i, BR, BC);	// move the ball as far as it goes with direction i

			// When the blue ball is in the hole
			if (BR == goalRow && BC == goalCol) continue;

			// Duplication of location of the balls : compare the row/col of each balls and adjust the location.
			// Adjusting the RR,RC,BR,BC
			if (RR == BR && RC == BC) {

				// when two balls are all in the hole -> do not queue
				if (RR == goalRow && RC == goalCol) continue;

				// when the balls are on the same place where is not a hole
				switch (i)
				{
				case 0: // Up
					cur.rR > cur.bR ? RR++ : BR++; break;
				case 1: // Down
					cur.rR > cur.bR ? BR-- : RR--; break;
				case 2: // Left
					cur.rC > cur.bC ? RC++ : BC++; break;
				case 3: // Right
					cur.rC > cur.bC ? BC-- : RC--; break;
				default:
					break;
				}
			}

			if (!visited[RR][RC][BR][BC]) {
				balls next;
				next.depth = cur.depth + 1;
				next.rR = RR; next.rC = RC; next.bR = BR; next.bC = BC;
				q.push(next);
			}

		}
	}

	return ans;
}