#include <iostream>
#include <vector>
using namespace std;
typedef struct cctv {
	int type, row, col;
}CCTVs;
int cctvCnt, maxRow, maxCol, ans = 100, map[10][10], directions[10];
int dr[] = { 0,-1,1,0,0 }, dc[] = { 0,0,0,-1,1 };
vector <CCTVs> cctv;

void back(int depth, int cur);
void marking();
void calculate();
void see(int row, int col, int dir);// 해당 위치에서 한 방향으로 쭉 칠하는 함수

int main() {
	cin >> maxRow >> maxCol;
	for (int r = 0; r < maxRow; r++)
		for (int c = 0; c < maxCol; c++) {
			cin >> map[r][c];
			if (map[r][c] < 6 && map[r][c]>0) {//cctv
				CCTVs temp;
				temp.col = c; temp.row = r; temp.type = map[r][c];
				cctv.push_back(temp);
				cctvCnt++;
			}
		}

	back(0, 0);
	cout << ans << endl;

	return 0;
}

void back(int depth, int cur) {
	if (depth == cctvCnt) {
		marking();
		calculate();
		return;
	}
	else {
			if (!directions[cur]) {
				switch (cctv[cur].type)
				{
				case 2:
					directions[cur] = 1;
					back(depth + 1, cur + 1);
					directions[cur] = 2;
					back(depth + 1, cur + 1);
					directions[cur] = 0;
					break;
				case 5:
					directions[cur] = 1;
					back(depth + 1, cur + 1);
					directions[cur] = 0;
					break;
				default:
					for (int i = 1; i <= 4; i++) {
						directions[cur] = i;
						back(depth + 1, cur + 1);
						directions[cur] = 0;
					}
					break;
				}
			}
	}
}

void see(int row, int col, int dir) {
	while (1) {
		row = row + dr[dir];
		col = col + dc[dir];
		if (row >= 0 && col >= 0 && row < maxRow && col < maxCol) {
			if (map[row][col] == 0) {
				map[row][col] = 7;
				continue;
			}
			else if (map[row][col] == 6)
				break;
		}
		else break;
	}
}

void marking() {
	for (int i = 0; i < cctvCnt; i++) {
		switch (cctv[i].type)
		{
		case 1://1번타입
			see(cctv[i].row, cctv[i].col, directions[i]);
			break;
		case 2://2번타입
			switch (directions[i])
			{
			case 1: //1번 방향: 좌우
				see(cctv[i].row, cctv[i].col, 3);
				see(cctv[i].row, cctv[i].col, 4);
				break;
			case 2: //2번 방향: 상하
				see(cctv[i].row, cctv[i].col, 1);
				see(cctv[i].row, cctv[i].col, 2);
				break;
			default:
				break;
			}
			break;
		case 3://3번타입(직각)
			switch (directions[i])
			{
			case 1: // 우상
				see(cctv[i].row, cctv[i].col, 4);
				see(cctv[i].row, cctv[i].col, 1);
				break;
			case 2: // 상좌
				see(cctv[i].row, cctv[i].col, 1);
				see(cctv[i].row, cctv[i].col, 3);
				break;
			case 3: // 좌하
				see(cctv[i].row, cctv[i].col, 3);
				see(cctv[i].row, cctv[i].col, 2);
				break;
			case 4: // 하우
				see(cctv[i].row, cctv[i].col, 2);
				see(cctv[i].row, cctv[i].col, 4);
				break;
			default:
				break;
			}
			break;
		case 4://4번타입
			switch (directions[i])
			{
			case 1://아래 뚫림
				see(cctv[i].row, cctv[i].col, 1);
				see(cctv[i].row, cctv[i].col, 3);
				see(cctv[i].row, cctv[i].col, 4);
				break;
			case 2://우측 뚫림
				see(cctv[i].row, cctv[i].col, 1);
				see(cctv[i].row, cctv[i].col, 2);
				see(cctv[i].row, cctv[i].col, 3);
				break;
			case 3://위쪽 뚫림
				see(cctv[i].row, cctv[i].col, 2);
				see(cctv[i].row, cctv[i].col, 3);
				see(cctv[i].row, cctv[i].col, 4);
				break;
			case 4://좌측 뚫림
				see(cctv[i].row, cctv[i].col, 1);
				see(cctv[i].row, cctv[i].col, 2);
				see(cctv[i].row, cctv[i].col, 4);
				break;
			default:
				break;
			}
			break;
		case 5://1번타입
			see(cctv[i].row, cctv[i].col, 1);
			see(cctv[i].row, cctv[i].col, 2);
			see(cctv[i].row, cctv[i].col, 3);
			see(cctv[i].row, cctv[i].col, 4);
			break;
		default:
			break;
		}
	}
}

void calculate() {
	int cnt = 0;
	for (int r = 0; r < maxRow; r++) {
		for (int c = 0; c < maxCol; c++) {
			if (map[r][c] == 0) cnt++;
			if (map[r][c] == 7)map[r][c] = 0;
		}
	}
	if (cnt < ans)ans = cnt;
}