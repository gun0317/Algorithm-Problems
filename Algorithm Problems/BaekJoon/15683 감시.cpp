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
void see(int row, int col, int dir);// �ش� ��ġ���� �� �������� �� ĥ�ϴ� �Լ�

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
		case 1://1��Ÿ��
			see(cctv[i].row, cctv[i].col, directions[i]);
			break;
		case 2://2��Ÿ��
			switch (directions[i])
			{
			case 1: //1�� ����: �¿�
				see(cctv[i].row, cctv[i].col, 3);
				see(cctv[i].row, cctv[i].col, 4);
				break;
			case 2: //2�� ����: ����
				see(cctv[i].row, cctv[i].col, 1);
				see(cctv[i].row, cctv[i].col, 2);
				break;
			default:
				break;
			}
			break;
		case 3://3��Ÿ��(����)
			switch (directions[i])
			{
			case 1: // ���
				see(cctv[i].row, cctv[i].col, 4);
				see(cctv[i].row, cctv[i].col, 1);
				break;
			case 2: // ����
				see(cctv[i].row, cctv[i].col, 1);
				see(cctv[i].row, cctv[i].col, 3);
				break;
			case 3: // ����
				see(cctv[i].row, cctv[i].col, 3);
				see(cctv[i].row, cctv[i].col, 2);
				break;
			case 4: // �Ͽ�
				see(cctv[i].row, cctv[i].col, 2);
				see(cctv[i].row, cctv[i].col, 4);
				break;
			default:
				break;
			}
			break;
		case 4://4��Ÿ��
			switch (directions[i])
			{
			case 1://�Ʒ� �ո�
				see(cctv[i].row, cctv[i].col, 1);
				see(cctv[i].row, cctv[i].col, 3);
				see(cctv[i].row, cctv[i].col, 4);
				break;
			case 2://���� �ո�
				see(cctv[i].row, cctv[i].col, 1);
				see(cctv[i].row, cctv[i].col, 2);
				see(cctv[i].row, cctv[i].col, 3);
				break;
			case 3://���� �ո�
				see(cctv[i].row, cctv[i].col, 2);
				see(cctv[i].row, cctv[i].col, 3);
				see(cctv[i].row, cctv[i].col, 4);
				break;
			case 4://���� �ո�
				see(cctv[i].row, cctv[i].col, 1);
				see(cctv[i].row, cctv[i].col, 2);
				see(cctv[i].row, cctv[i].col, 4);
				break;
			default:
				break;
			}
			break;
		case 5://1��Ÿ��
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