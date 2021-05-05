// TLE
#include <iostream>
#include <stack>
#include <string.h>
#define pair pair <int,int>
using namespace std;
int map[6000][6000];
int dx[] = { 0,0,-1,1,1,-1,1,-1 };
int dy[] = { -1,1,0,0,1,1,-1,-1};

void dfs(pair start) {
	stack <pair> s;
	s.push(start);
	map[start.first][start.second] = 0;

	while (!s.empty())
	{
		pair cur = s.top();
		s.pop();

		for (int i = 0; i < 8; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (map[nx][ny] && nx >= 0 && ny >= 0 && nx < 5999 && ny < 5999) {
				map[nx][ny] = 0;
				s.push(make_pair(nx, ny));
			}
		}
	}
}

double distance(int ax, int ay, int bx, int by) {
	return (ax - bx)*(ax - bx) + (ay - by)*(ay - by);
}

void mark(int x, int y, int r) {
	double nx = x, ny = y;
	for (int i = 0; i < 5999; i++)
		for (int j = 0; j < 5999; j++) {
			if (distance(nx, ny, i, j) <= r*r) {
				map[i][j] = 1;
			}

		}
}

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		//�׽�Ʈ ���̽��� map�� ���� 0���� �ʱ�ȭ
		for (int i = 0; i < 5999; i++)
			memset(map[i], 0, sizeof(int) * 5999);

		int N, x, y, r, components = 0;
		cin >> N;
		//x,y,r���� �޾Ƽ� �ش� ������ �ִ� ������ 1�θ������
		for (int i = 0; i < N; i++) {
			cin >> x >> y >> r;
			mark(x, y, r);
		}
		for (int i = 0; i < 5999; i++)
			for (int j = 0; j < 5999; j++) {
				if (map[i][j]) {
					components++;
					dfs(make_pair(i, j));

				}
			}
		cout << components << endl;
	}

	return 0;
}
