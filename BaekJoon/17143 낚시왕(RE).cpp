#include <iostream>
using namespace std;

int maxR, maxC, shark_num, sharks_caught;
int dr[] = { 0,-1,1,0,0 }, dc[] = { 0,0,0,1,-1 };
typedef struct sharkNode {
	int speed, dir;
}sharkNode;
sharkNode sharks[10010];
int map[110][110], next_map[110][110];

int closest_shark(int col) {
	int toReturn = 0;
	for (int r = 1; r <= maxR; r++) {
		if (map[r][col] > 0) {
			toReturn = map[r][col];
			map[r][col] = 0;
			break;
		}
	}

	return toReturn;
}
// shark ũ�Ⱑ �� �ٸ��� �� ���� �ִ� 10000�̴ϱ�
// pair <int,int> �迭 10010 ĭ �����, index�� size, first�� ����, second�� �ӷ�
// �׸��� map���� size�� ����(r�� c�� ����Ǵ� ���)
// move�� r�� c�� ���鼭 size�� 1�̻��̸� �ش� size�� shark array�� ���� ����
void move_sharks() {
	for (int r = 1; r <= maxR; r++) {
		for (int c = 1; c <= maxC; c++) {
			int curSize = map[r][c];
			if (curSize > 0) {
				int curDir = sharks[curSize].dir;
				int curSpd = sharks[curSize].speed;
				int nextR = r + dr[curDir]*curSpd;
				int nextC = c + dc[curDir]*curSpd;

				while (nextR < 1 || nextR > maxR) {
					if (nextR < 1) {
						curDir = 2;
						nextR = 1 - nextR  + 1;
					}
					if (nextR > maxR) {
						curDir = 1;
						nextR = maxR - (nextR - maxR);
					}
				}

				while (nextC < 1 || nextC > maxC) {
					if (nextC < 1) {
						curDir = 3;
						nextC = 1 - nextC + 1;
					}
					if (nextC > maxC) {
						curDir = 4;
						nextC = maxC - (nextC - maxC);
					}
				}

				if (next_map[nextR][nextC] < curSize) {
					next_map[nextR][nextC] = curSize;
				}
				sharks[curSize].dir = curDir;
				map[r][c] = 0;
			}
		}
	}

	for (int r = 1; r <= maxR; r++) 
		for (int c = 1; c <= maxC; c++) {
			map[r][c] = next_map[r][c];
			next_map[r][c] = 0;
		}
}

int main() {
	cin >> maxR >> maxC >> shark_num;
	for (int i = 0; i < shark_num; i++) {
		int r, c, spd, dr, sz;
		scanf("%d %d %d %d %d", &r, &c, &spd, &dr, &sz);
		sharks[sz].dir = dr;
		sharks[sz].speed = spd;
		map[r][c] = sz;
	}

	for (int c = 1; c <= maxC; c++) {
		sharks_caught += closest_shark(c);
		move_sharks();
	}
	cout << endl;
	cout << sharks_caught << endl;

	return 0;
}