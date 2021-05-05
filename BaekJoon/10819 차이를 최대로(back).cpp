#include <iostream>
#include <algorithm>
using namespace std;
int ans, N, arr[10], visited[10],temp[10];

void back(int depth, int* comb) {
	if (depth == N) {
		int sum = 0;
		for (int i = 0; i < N-1; i++) {
			sum += abs(comb[i + 1] - comb[i]);
		}
		if (ans < sum) ans = sum;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i]++;
			comb[depth] = arr[i];
			back(depth + 1, comb);
			visited[i]--;
		}
	}
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	back(0,temp);
	cout << ans << endl;


	return 0;
} 