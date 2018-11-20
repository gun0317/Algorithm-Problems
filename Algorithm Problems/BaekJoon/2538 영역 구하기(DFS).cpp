//#include <iostream>
//#include <stack>
//#include <algorithm>
//#define pair pair <int,int>
//using namespace std;
//int M, N, K, toVisit[110][110], area[10000],idx;	//map을 따로 받지 않고 visit여부를 표시하는 그래프만 받는다. 직사각형으로 덮이는 부분은 1로, 빈 공간은 0으로 저장.
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };	//움직임 정의
//
//void DFS(pair start) {
//	stack <pair> s;
//	s.push(start);
//	toVisit[start.first][start.second] = 1;	//방문한 초기지점 표시
//	area[idx]++;
//	while (!s.empty()) {
//		pair cur = s.top();
//		s.pop();
//
//		for (int i = 0; i < 4; i++) {		//상하좌우 점으로 이동
//			int newX = cur.first + dx[i];
//			int newY = cur.second + dy[i];
//
//			if (!toVisit[newX][newY] && newX >= 0 && newY >= 0 && newX < N && newY < M) {	//boundary && 방문여부 check
//				toVisit[newX][newY] = 1;
//				area[idx]++;
//				s.push(make_pair(newX, newY));
//			}
//		}
//	}
//	idx++;	//한번의 DFS가 끝나면 다른 영역을 볼 것이므로 area의 index를 증가시켜놓는다.
//}
//
//int main() {
//	cin >> M >> N >> K;
//	int Lx, Ly, Rx, Ry, components =0;
//	for (int i = 0; i < K; i++) {
//		cin >> Lx >> Ly >> Rx >> Ry;
//		for (int j = Lx; j <= Rx-1; j++)		//직사각형의 좌하단점과 우상단점의 정보를 이용해서
//			for (int k = Ly; k <= Ry-1; k++)	//방문하지 않을 부분(직사각형이 이미 덮여있는 부분)을 1로 구분해놓는다.
//				toVisit[j][k] = 1;
//	}
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++) 
//			if (!toVisit[i][j])
//			{
//				components++;			//connected components를 세는 변수
//				DFS(make_pair(i, j));	//toVisit[i][j] = 0 인 점을 방문하여 DFS하면서 area를 계산한다. 이때 방문한 곳은 1로 바꿔서 다시 방문하지 않게 한다.
//			}
//
//	sort(area, area + components);		//저장해놓은 area를 오름차 순으로 정렬
//
//	cout << components << endl;
//
//	for (int i = 0; i < components; i++)
//		cout << area[i] << " ";
//	return 0;
//}