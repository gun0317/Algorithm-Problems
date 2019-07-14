//#include <iostream>
//#include <queue>
//#define pair pair <int, int> 
//#define chk newRow <= N && newCol <= M
//using namespace std;
//int N, M;
//int map[1010][1010], dp[1010][1010], ans;
//pair dest;
//int moves[3][2] = { {1,0},{0,1},{1,1} };
//
//void BFS() {
//	queue <pair> q;
//	q.push(make_pair(1, 1));
//	dp[1][1] = map[1][1];
//
//	while (!q.empty()) {
//		pair cur = q.front();
//		int row = cur.first, col = cur.second;
//		q.pop();
//		//current candies
//		int candyNow = dp[cur.first][cur.second];
//		//new moves
//		for (int i = 0; i < 3; i++) {
//			int newRow = row + moves[i][0];
//			int newCol = col + moves[i][1];
//			//boundary check
//			if (chk && (candyNow + map[newRow][newCol] > dp[newRow][newCol]) || (dp[newRow][newCol] == -1)) {
//				q.push(make_pair(newRow, newCol));
//				dp[newRow][newCol] = candyNow + map[newRow][newCol];
//			}
//		}
//
//	}
//
//	ans = dp[N][M];
//}
//
//int main() {
//	cin >> N >> M;
//	for (int r = 1; r <= N; r++)
//		for (int c = 1; c <= M; c++)
//		{
//			cin >> map[r][c];
//			dp[r][c] = - 1;
//		}
//
//	dest = make_pair(N, M);
//	BFS();
//
//	cout << ans << endl;
//
//	return 0;
//}