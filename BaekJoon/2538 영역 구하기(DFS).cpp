#include <iostream>
#include <stack>
#include <algorithm>
#define pair pair <int,int>
using namespace std;
int M, N, K, toVisit[110][110], area[10000],idx;	//map�� ���� ���� �ʰ� visit���θ� ǥ���ϴ� �׷����� �޴´�. ���簢������ ���̴� �κ��� 1��, �� ������ 0���� ����.
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };	//������ ����

void DFS(pair start) {
	stack <pair> s;
	s.push(start);
	toVisit[start.first][start.second] = 1;	//�湮�� �ʱ����� ǥ��
	area[idx]++;
	while (!s.empty()) {
		pair cur = s.top();
		s.pop();

		for (int i = 0; i < 4; i++) {		//�����¿� ������ �̵�
			int newX = cur.first + dx[i];
			int newY = cur.second + dy[i];

			if (!toVisit[newX][newY] && newX >= 0 && newY >= 0 && newX < N && newY < M) {	//boundary && �湮���� check
				toVisit[newX][newY] = 1;
				area[idx]++;
				s.push(make_pair(newX, newY));
			}
		}
	}
	idx++;	//�ѹ��� DFS�� ������ �ٸ� ������ �� ���̹Ƿ� area�� index�� �������ѳ��´�.
}

int main() {
	cin >> M >> N >> K;
	int Lx, Ly, Rx, Ry, components =0;
	for (int i = 0; i < K; i++) {
		cin >> Lx >> Ly >> Rx >> Ry;
		for (int j = Lx; j <= Rx-1; j++)		//���簢���� ���ϴ����� �������� ������ �̿��ؼ�
			for (int k = Ly; k <= Ry-1; k++)	//�湮���� ���� �κ�(���簢���� �̹� �����ִ� �κ�)�� 1�� �����س��´�.
				toVisit[j][k] = 1;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			if (!toVisit[i][j])
			{
				components++;			//connected components�� ���� ����
				DFS(make_pair(i, j));	//toVisit[i][j] = 0 �� ���� �湮�Ͽ� DFS�ϸ鼭 area�� ����Ѵ�. �̶� �湮�� ���� 1�� �ٲ㼭 �ٽ� �湮���� �ʰ� �Ѵ�.
			}

	sort(area, area + components);		//�����س��� area�� ������ ������ ����

	cout << components << endl;

	for (int i = 0; i < components; i++)
		cout << area[i] << " ";
	return 0;
}