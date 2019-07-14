#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define cur map[r][c]
using namespace std;

typedef struct Ground_ {
	int fertility;
	vector <int> alive;
	vector <int> dead;
}Ground;

int dr[] = { -1,1,0,0,1,1,-1,-1 }, dc[] = { 0,0,-1,1,1,-1,1,-1 };
int N, numTrees, years, ans, fertilizer[12][12];
Ground map[12][12];
void aYear();

int main() {
	cin >> N >> numTrees >> years;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++) {
			cin >> fertilizer[r][c];
			map[r][c].fertility = 5;
		}

	for (int i = 0; i < numTrees; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		map[x][y].alive.push_back(z);
	}

	for (int i = 0; i < years; i++)
		aYear();

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			ans += map[r][c].alive.size();

	cout << ans << endl;

	return 0;
}

void aYear() {

	// SPRING
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++) {
			sort(map[r][c].alive.begin(), map[r][c].alive.end());
			if (map[r][c].alive.size() > 0) {
				vector <int> tempAlive;
				for (int i = 0; i < map[r][c].alive.size(); i++) {
					int curAge = map[r][c].alive[i];
					if (map[r][c].fertility - curAge >= 0) {
						map[r][c].fertility -= curAge;
						tempAlive.push_back(curAge + 1);
					}
					else 	// dead
						map[r][c].dead.push_back(curAge);
				}
				map[r][c].alive = tempAlive;
			}
		}

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++) {
			// SUMMER
			for (int i = 0; i < map[r][c].dead.size(); i++)
				cur.fertility += map[r][c].dead[i] / 2;
			map[r][c].dead.clear();

			// FALL
			for (int i = 0; i < map[r][c].alive.size(); i++) {
				if (map[r][c].alive[i] % 5 == 0) {	//reproduce case
					for (int j = 0; j < 8; j++) {
						int newR = r + dr[j], newC = c + dc[j];
						if (newR <= N && newR >= 1 && newC <= N && newC >= 1) {
							map[newR][newC].alive.push_back(1);
						}
					}
				}
			}

			// WINTER
			cur.fertility += fertilizer[r][c]; map[r][c].fertility;
		}
}