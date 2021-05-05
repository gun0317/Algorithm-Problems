#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int N, score, P;
int scores[51];

int main() {
	cin >> N >> score >> P;
	int i;
	for (i = 0; i < N; i++)
		cin >> scores[i];
	scores[i] = score;

	sort(scores, scores + N+1,greater <int>());
	int pos;

	if (N < P) 
		for (int j = 0; j <= N; j++) {
			if (scores[j] == score) {
				cout << j+1;
				return 0;
			}
		}
	
	else {
		int temp;
		if (scores[N] == score) {
			cout << -1;
			return 0;
		}
		for (int j = 0; j <= N; j++) {
			if (scores[j] <= score) {
				cout << j + 1;
				return 0;
			}
			
		}
	}


	return 0;
}