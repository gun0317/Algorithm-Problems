#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct shark {
	int vel, dir, size;
}shark;

// Up Down Right Left
int dr[] = { -100,-1,1,0,0 }, dc[] = { -100,0,0,1,-1 };
int maxR, maxC, sharkNum, personC;
shark sharkMap[110][110],nextSharkMap[110][110];

void move() {
	for (int r = 1; r <= maxR; r++) {
		for (int c = 1; c <= maxC; c++) {
			int curR = r, curC = c,curDir = sharkMap[r][c].dir;
			if (sharkMap[r][c].size > 0) {
				for (int i = 0; i < sharkMap[r][c].vel; i++) {
					switch (curDir) {
					case 1:// UP
						curR--;
						break;
					case 2:// Down
						curR++;
						break;
					case 3:// Right
						curC++;
						break;
					case 4:// Left
						curC--;
						break;
					}
					if (curR == 0) {
						curR = 2;
						curDir = 2;
					}
					else if (curR == maxR + 1) {
						curR = maxR - 1;
						curDir = 1;
					}
					else if (curC == 0) {
						curC = 2;
						curDir = 3;
					}
					else if (curC == maxC + 1) {
						curC = maxC - 1;
						curDir = 4;
					}
				}
				// Sharks Eating Themselves
				int alreadySize = nextSharkMap[curR][curC].size;
				if (alreadySize < sharkMap[r][c].size) {
					nextSharkMap[curR][curC].dir = curDir;
					nextSharkMap[curR][curC].size = sharkMap[r][c].size;
					nextSharkMap[curR][curC].vel = sharkMap[r][c].vel;
				}
			}
		}
	}
	for (int r = 1; r <= maxR; r++) {
		for (int c = 1; c <= maxC; c++) {
			sharkMap[r][c].dir = nextSharkMap[r][c].dir;
			sharkMap[r][c].size = nextSharkMap[r][c].size;
			sharkMap[r][c].vel = nextSharkMap[r][c].vel;
			nextSharkMap[r][c].size = 0;
		}
	}
}

int fishing() {
	int toReturn = 0;
	for (int r = 1; r <= maxR; r++) {
		if (sharkMap[r][personC].size > 0) {
			toReturn = sharkMap[r][personC].size;
			sharkMap[r][personC].size = 0;
			break;
		}
	}

	return toReturn;
}

int main() {
	cin >> maxR >> maxC >> sharkNum;
	int ans = 0;
	personC = 0;
	// Getting input
	for (int i = 0; i < sharkNum; i++) {
		int _r, _c, _vel, _dir, _size;
		scanf(" %d %d %d %d %d", &_r, &_c, &_vel, &_dir, &_size);
		sharkMap[_r][_c].dir = _dir;
		sharkMap[_r][_c].size = _size;
		sharkMap[_r][_c].vel = _vel;
	}

	// Simulation
	for (personC = 1; personC <= maxC; personC++) {
		int caught = fishing();
		if (caught > 0) {
			ans += caught;
		}
		move();		// shark have to move within one operation(mathmatical) + only bigger shark survives.
	}

	cout << ans << endl;

	return 0;
}