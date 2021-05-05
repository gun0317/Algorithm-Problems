#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stack>
#include <queue>
#include <string.h> // test case�� memset���
#define pair pair <int,int>
using namespace std;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int N, M, K, visited[100100];

void BFS() {
	queue <pair> q;
	q.push(make_pair(N,0));
	visited[N]++;
	while (!q.empty()) {
		pair cur = q.front();
		q.pop();
		if (cur.first == K) {
			cout << cur.second;
			return;
		}
		if (cur.first + 1 <= 100000 && !visited[cur.first + 1]) {
			visited[cur.first + 1] =1 ;
			q.push(make_pair(cur.first + 1, cur.second + 1));
		}
		if (cur.first - 1 >= 0 && !visited[cur.first - 1]) {
			visited[cur.first - 1]=1;
			q.push(make_pair(cur.first - 1, cur.second + 1));
		}
		if (cur.first * 2 <= 100000 && !visited[cur.first * 2]) {
			visited[cur.first * 2]=1;
			q.push(make_pair(cur.first * 2, cur.second + 1));
		}
	}

}

int main() {
	cin >> N >> K;
	BFS();

	return 0;
}