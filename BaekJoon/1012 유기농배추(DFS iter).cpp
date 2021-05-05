#include <iostream>
#include <stack>
#define pair pair <int,int>
using namespace std;

//map�� ���� �׷��� �״�� ����, toVisit�� �湮�ؾ��ϴ� ���ߴ� 1, �湮�ߴ� ���ߴ� 0���� �ؼ� �ߺ� �湮�� ����
int map[60][60], toVisit[60][60], M, N, K;
int moves[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

void DFS(pair vtx) {

	stack <pair> s;
	s.push(vtx);
	toVisit[vtx.first][vtx.second] = 0;

	while (!s.empty()) 
	{
		pair cur = s.top();
		s.pop();

		for (int k = 0; k < 4; k++) {
			//newX�� newY, moves�� �����¿� ��ĭ���� �����δٴ� ������ �ݿ�
			int newX = cur.first + moves[k][0];
			int newY = cur.second + moves[k][1];
			//�����¿� boundary check && �湮�ؾ��ϴ� �����̸� �湮. �̷������� ��� ���ߵ��� �湮�ϵ� connected component�� ������ main()���� ī��Ʈ
			if (toVisit[newX][newY] && newX >= 0 && newY >= 0 && newX < M && newY < N) {
				toVisit[newX][newY] = 0;
				s.push(make_pair(newX, newY));
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) 
	{
		int x, y,cnt = 0;
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			map[x][y] = 1;
			toVisit[x][y] = 1;
		}
		
		//���� ����Ǿ��������� connected component�� ��� �������� �ݺ��� ���
		for (int i = 0; i < M; i++) 
			for (int j = 0; j < N; j++) 
				if (toVisit[i][j]) {
					cnt++;
					DFS(make_pair(i, j));
				}
		cout << cnt << endl;
	}
	return 0;
}