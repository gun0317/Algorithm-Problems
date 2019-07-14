//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <functional>
//#include <queue>
//#include <stack>
//#include <string.h>
//#define pair pair <int, int> 
//using namespace std;
//int map[110][110], dpMap[110][110], N;
//
//void dBFS() {
//	queue <pair> q;
//	q.push(make_pair(0, 0));
//
//	while (!q.empty()){
//		int r = q.front().first;
//		int c = q.front().second;
//		q.pop();
//		int newR = r, newC = c;
//		for (int i = 0; i < map[r][c]; i++) {
//			newR++;
//			newC++;
//		}
//		if (map[newR][c] > 0 && newR < N){
//			dpMap[newR][c]++;
//			q.push(make_pair(newR, c));
//		}
//		else if (map[newR][c] == 0 && newR == N - 1 && c == N - 1 && newR < N)
//			dpMap[newR][c]++;
//
//		if (map[r][newC] > 0 && newC < N){
//			dpMap[r][newC]++;				
//			q.push(make_pair(r, newC));
//			
//		}
//		else if (map[r][newC] == 0 && newC == N - 1 && r == N - 1 && newC < N)
//			dpMap[r][newC]++;
//	}
//}
//
//int main() {
//	cin >> N;
//	for (int r = 0; r < N; r++)
//		for (int c = 0; c < N; c++)
//			cin >> map[r][c];
//
//	dBFS();
//
//	cout << dpMap[N - 1][N - 1];
//
//
//	return 0;
//x}