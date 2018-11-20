//#include <iostream>
//#include <queue>
//#include <algorithm>
//#include <cstdio>
//using namespace std;
//
//
//int moves[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
//
//int arr[8][8], startX[10], startY[10];
//int N, M, idx;
//int ax, ay, bx, by, cx, cy;
//
//void BFS() {
//	queue < pair<int, int> > q;
//	for (int i = 0; i < idx; i++)
//		q.push(make_pair(startX[i], startY[i]));
//	
//	for(ax = 0;ax<)
//
//	while (!q.empty())
//	{
//		pair <int, int> cur = q.front();
//		q.pop();
//
//		for (int j = 0; j < 4; j++)
//			{
//				int newY = cur.first + moves[j][0];
//				int newX = cur.second + moves[j][1];
//				if (newX < M && 0 <= newX && newY < N && 0 <= newY)
//				{
//					switch (arr[newX][newY]) {
//					case 0:
//						arr[newX][newY] = 1;
//						break;
//					case 1:
//
//						break;
//					case 2:
//						q.push(make_pair(newX, newY));
//						break;
//
//					default:
//						break;
//					}
//					
//				}
//			}
//	}
//
//
//}
//
//int main() {
//	cin >> N >> M;
//	int i, j;
//
//	for (i = 0; i < N; i++)
//		for (j = 0; j < M; j++)
//		{
//			scanf("%d", &arr[i][j]);
//			if (arr[i][j] == 2)
//			{
//				startX[idx] = i;
//				startY[idx++] = j;
//			}
//			
//		}
//
//
//	BFS();
//	int cnt = 0;
//	for (i = 0; i < N; i++)
//		for (j = 0; j < M; j++)
//			if (arr[i][j] == 0)
//				cnt++;
//			
//	cout << cnt << endl;
//		
//
//
//	return 0;
//}