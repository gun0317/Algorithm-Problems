#include <iostream>
#include <vector>
#define BOUNDARY (newR >= 0 && newR < maxR && newC >= 0 && newC < maxC && map[newR][newC] != -1)
using namespace std;
int map[55][55],nextMap[55][55];
int maxR, maxC, t;
int dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 };
vector <pair <int, int>> purifier;

void airConditioning(int dir,int &r, int &c, int stop) {
	// ������ȭ�� �ٶ��� ���鼭 map[r][c]�� �ϳ��� '����' �Լ�. dir�� 0,1,2,3 (��,��,��,��). ���������� ��.
	
	while (true) {
		r += dr[dir], c += dc[dir];
		if (stop == r && (r >= 0 && r < maxR && c >= 0 && c < maxC)) {
			map[r - dr[dir]][c - dc[dir]] = map[r][c];
			return;
		}
		if (!(r >= 0 && r < maxR && c >= 0 && c < maxC && map[r][c] != -1)) {
			r -= dr[dir]; c -= dc[dir];
			return;
		}
		else {// ���ο� ���� �ٶ��� ���డ���� ��ġ�϶�
			if (map[r - dr[dir]][c - dc[dir]] == -1) {
				continue;
			}
			else {
				map[r-dr[dir]][c-dc[dir]] = map[r][c];
			}
		}
	}
}

void diffusion(int r, int c) {
	// Ư�� ��(r,c)������ ������ Ȯ�� ��Ű�� �Լ�
	int temp = map[r][c];
	nextMap[r][c] += temp;
	for (int i = 0; i < 4; i++) {
		int newR = r + dr[i], newC = c + dc[i];
		if (BOUNDARY) {
			nextMap[newR][newC] += temp/5;
			nextMap[r][c] -= temp / 5;
		}
	}
}

int main() {
	cin >> maxR >> maxC >> t;
	for (int r = 0; r < maxR; r++)
		for (int c = 0; c < maxC; c++) {
			cin >> map[r][c];
			if (map[r][c] == -1) 
				purifier.push_back({ r,c });
			
		
		}
	while (t--) {
		// Diffuse
		for (int r = 0; r < maxR; r++) {
			for (int c = 0; c < maxC; c++) {
				if(map[r][c] >0) diffusion(r, c);
			}
		}
		// Copy
		for (int r = 0; r < maxR; r++) {
			for (int c = 0; c < maxC; c++) {
				if (map[r][c] != -1) map[r][c] = nextMap[r][c];
				nextMap[r][c] = 0;
			}
		}

		// Air Conditioning
		// ���κ�: ��, �� ��, ��(0,3,1,2)
		int upR = purifier[0].first;
		int r1 = upR;
		int upC = purifier[0].second;
		airConditioning(0, upR, upC,-1);		
		airConditioning(3, upR, upC,-1);		
		airConditioning(1, upR, upC,r1);//upR == r1�̸� break;
		airConditioning(2, upR, upC,-1);
		map[purifier[0].first][purifier[0].second + 1] = 0;

		// �Ʒ��κ�: ��,��,��,��(1,3,0,2)
		int downR = purifier[1].first;
		int r2 = downR;
		int downC = purifier[1].second;
		airConditioning(1, downR, downC,-1);
		airConditioning(3, downR, downC,-1);
		airConditioning(0, downR, downC,r2);//downR == r2�� break		
		airConditioning(2, downR, downC,-1);
		map[purifier[1].first][purifier[1].second + 1] = 0;
	}
	int ans = 0;
	for (int r = 0; r < maxR; r++)
		for (int c = 0; c < maxC; c++)
			if (map[r][c] > 0) ans += map[r][c];

	cout << ans << endl;
	return 0;
}