#include <iostream>
using namespace std;

int ans = 0x7fffff, N, M, K, arr[55][55], originalArr[55][55], changeR[10], changeC[10], changeS[10], visited[10];
int combi[10];

void change(int* combination);
int calMin();

void back(int depth, int combination[10]) {
	if (depth == K) {
		change(combination);
		return;
	}
	else {
		for (int i = 0; i < K; i++) {
			if (!combination[i]) {
				combination[i] = depth + 1;
				back(depth + 1,combination);
				combination[i] = 0;
			}
		} 
	}
}

void change(int* combination) {
	for (int idx = 0; idx < K; idx++) {
			int r = changeR[combination[idx]], c = changeC[combination[idx]],
				curS = changeS[combination[idx]];
		for (int s = 1; s <= curS; s++) {
			int temp1 = arr[r - s][c - s];
			int temp2 = arr[r - s][c + s];
			int temp3 = arr[r + s][c - s];
			int temp4 = arr[r + s][c + s];
			for (int i = 0; i <= 2 * s - 1; i++) {
				
				arr[r + s - i][c + s] = arr[r + s - i - 1][c + s];
				arr[r + s][c - s + i] = arr[r + s][c - s + i + 1];
				arr[r - s + i][c - s] = arr[r - s + i + 1][c - s];
				arr[r - s][c + s - i] = arr[r - s][c + s - i - 1];
			}
			arr[r - s][c - s + 1] = temp1;
			arr[r - s + 1][c + s] = temp2;
			arr[r + s - 1][c - s] = temp3;
			arr[r + s][c + s - 1] = temp4;
		}
	}
	int localMin = calMin();
	if (ans > localMin) ans = localMin;
	for (int r = 1; r <= N; r++) for (int c = 1; c <= M; c++) arr[r][c] = originalArr[r][c];
}

int calMin() {
	int toReturn = 0x7fffff;
	for (int r = 1; r <= N; r++) {
		int localMin = 0;
		for (int c = 1; c <= M; c++) localMin += arr[r][c];
		if (localMin < toReturn) toReturn = localMin;
	}
	return toReturn;
}

int main() {
	cin >> N >> M >> K;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= M; c++) {
			scanf(" %d", &arr[r][c]);
			originalArr[r][c] = arr[r][c];
		}
	
	for (int i = 1; i <= K; i++)
		scanf(" %d %d %d", &changeR[i], &changeC[i], &changeS[i]);

	back(0, combi);
	cout << ans << endl;

	return 0;
}