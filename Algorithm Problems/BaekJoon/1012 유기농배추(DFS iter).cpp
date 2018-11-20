//#include <iostream>
//#include <stack>
//#define pair pair <int,int>
//using namespace std;
//
////map은 배추 그래프 그대로 저장, toVisit은 방문해야하는 배추는 1, 방문했던 배추는 0으로 해서 중복 방문을 막음
//int map[60][60], toVisit[60][60], M, N, K;
//int moves[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
//
//void DFS(pair vtx) {
//
//	stack <pair> s;
//	s.push(vtx);
//	toVisit[vtx.first][vtx.second] = 0;
//
//	while (!s.empty()) 
//	{
//		pair cur = s.top();
//		s.pop();
//
//		for (int k = 0; k < 4; k++) {
//			//newX와 newY, moves는 상하좌우 한칸씩만 움직인다는 조건을 반영
//			int newX = cur.first + moves[k][0];
//			int newY = cur.second + moves[k][1];
//			//상하좌우 boundary check && 방문해야하는 배추이면 방문. 이런식으로 모든 배추들을 방문하되 connected component의 갯수를 main()에서 카운트
//			if (toVisit[newX][newY] && newX >= 0 && newY >= 0 && newX < M && newY < N) {
//				toVisit[newX][newY] = 0;
//				s.push(make_pair(newX, newY));
//			}
//		}
//	}
//}
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) 
//	{
//		int x, y,cnt = 0;
//		cin >> M >> N >> K;
//		for (int i = 0; i < K; i++) {
//			cin >> x >> y;
//			map[x][y] = 1;
//			toVisit[x][y] = 1;
//		}
//		
//		//서로 연결되어있지않은 connected component를 모두 돌기위해 반복문 사용
//		for (int i = 0; i < M; i++) 
//			for (int j = 0; j < N; j++) 
//				if (toVisit[i][j]) {
//					cnt++;
//					DFS(make_pair(i, j));
//				}
//		cout << cnt << endl;
//	}
//	return 0;
//}