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
// shark 크기가 다 다르고 그 수가 최대 10000이니까
// pair <int,int> 배열 10010 칸 만들고, index는 size, first는 방향, second는 속력
// 그리고 map에는 size만 저장(r와 c도 저장되는 결과)
// move는 r와 c을 돌면서 size가 1이상이면 해당 size의 shark array로 가서 접근
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