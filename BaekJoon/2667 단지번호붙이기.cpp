#include <iostream>
#include <stack>
#include <algorithm>
#define pair pair <int,int>
using namespace std;
int N, map[30][30], area[1000], idx = -1;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(pair start) {
	stack <pair> s;
	s.push(start);
	map[start.first][start.second] = 0;
	idx++;
	area[idx]++;
	while (!s.empty())
	{
		pair cur = s.top();
		s.pop();


		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (map[nx][ny] && nx >= 0 && ny >= 0 && nx < N && ny < N) {
				area[idx]++;
				map[nx][ny] = 0;
				s.push(make_pair(nx, ny));
			}
		}

	}
}
int main() {
	cin >> N;
	int temp, comp = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (map[i][j]) {
				comp++;
				dfs(make_pair(i, j));
			}
		
		}

	sort(area, area + comp);
	cout << comp << endl;
	int i = 0;
	while (comp--)
	{
		cout << area[i++] << endl;
	}

	return 0;
}