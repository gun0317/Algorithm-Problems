//#include <iostream>
//#include <queue>
//#include <string.h>
//#define UP 0
//#define RIGHT 1
//#define DOWN 2
//#define LEFT 3
//#define bCheck newR > N || newC >N || newR ==0 || newC == 0
//using namespace std;
//
////move: up right down left(0,1,2,3)
//int moving[][2] = { {-1,0},{0,1},{1,0},{0,-1} };
//
//typedef struct snake_ {
//	//dir: U, D, L, R (up down left right)
//	int dir;
//	int body[110][110];
//	int headR;
//	int headC;
//	int tailR;
//	int tailC;
//}snake;
//
//int N, K, L;
//int time, flag = 0;
//int apple[110][110];
//queue <pair <int, char>> moves;
//
////function that checks boundary and moves
//void boundaryCheck(snake *s) {
//	int newR = s->headR + moving[s->dir][0];
//	int newC = s->headC + moving[s->dir][1];
//
//	//out of the map & eating itself
//	if (bCheck || s->body[newR][newC] > 0) {
//		flag++;
//		return;
//	}
//	
//	//Update: not eating apple
//	if(!apple[newR][newC])
//	{
//		for (int r = 1; r <= N; r++) {
//			for (int c = 1; c <= N; c++) {
//				if (s->body[r][c] > 0) {
//					s->body[r][c] -= 1;
//				}
//			}
//		}
//	}
//	//Update: eating apple
//	else {
//		apple[newR][newC] = 0;
//	}
//
//	//snake's head is moved & body is updated
//	s->body[newR][newC] = s->body[s->headR][s->headC] + 1;
//	s->headR = newR;
//	s->headC = newC;
//
//	//direction changing
//	if (!moves.empty() && time == moves.front().first) {
//		//clockwise
//		if (moves.front().second == 'D') {
//			s->dir = (s->dir + 1) % 4;
//		}
//		//counter clockwise
//		else {
//			s->dir = (s->dir + 3) % 4;
//		}
//		moves.pop();
//	}
//
//
//}
//
//int main() {
//	
//	//getting input//
//	cin >> N >> K;
//	for (int i = 0; i < K; i++) {
//		int r, c;
//		cin >> r >> c;
//		apple[r][c] = 1;
//	}
//	cin >> L;
//	for (int i = 0; i < L; i++) {
//		int X;
//		char C;
//		cin >> X >> C;
//		moves.push(make_pair(X, C));
//	}
//	//
//
//	//initialize snake
//	snake s;
//	s.dir = RIGHT;
//	for (int i = 0; i < 110; i++)
//		memset(s.body[i], 0, sizeof(int) * 110);
//	s.body[1][1] = 1;
//	s.headR = 1;
//	s.headC = 1;
//	s.tailR = 1;
//	s.tailC = 1;
//	//
//
//	//simulate each second
//	while (1) {
//		time++;
//		boundaryCheck(&s);
//		if(flag>0)	break;
//	}
//	//
//
//	cout << time << endl;
//
//	return 0;
//}