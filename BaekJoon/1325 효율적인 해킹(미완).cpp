#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int N, M, arr[10010][10010]; //index 1���� ����

void dfs() {

}

int main() {
	cin >> N >> M;
	int A, B;
	for (int i = 1; i <= M; i++) {
		cin >> A >> B;
		arr[A][B] = 1;
	}


	return 0;
}