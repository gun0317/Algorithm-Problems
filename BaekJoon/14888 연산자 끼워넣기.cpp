#include <iostream>
using namespace std;
int N, arr[20], ansMax, ansMin, visited[20], firstFlag;

// 1: plus, 2: minus, 3: multi, 4: div
void back(int depth, int cur, int plus, int minus, int multi, int div);
int calculate(int *visited);

int main() {
	int plus, minus, multi, div;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> plus >> minus >> multi >> div;

	back(0, 0, plus, minus, multi, div);
	cout << ansMax << "\n" << ansMin << endl;
	return 0;
}

void back(int depth, int cur, int plus, int minus, int multi, int div) {
	if (depth == N - 1) {
		int result = calculate(visited);
		
		if (firstFlag == 0) {
			firstFlag = 1;
			ansMax = result;
			ansMin = result;
		}
		else {
			if (result > ansMax) ansMax = result;
			if (result < ansMin) ansMin = result;
		}
	/*	printf("current visited[] = ");
		for (int i = 0; i < N - 1; i++)
			printf("%d ", visited[i]);*/
		return;
	}
	else {
		for (int i = 0; i < N - 1; i++) {
			if (!visited[i]) {
				if (plus > 0) {
					visited[i] = 1;
					back(depth + 1, i, plus - 1, minus, multi, div);
					visited[i] = 0;
				}
				else if (minus > 0) {
					visited[i] = 2;
					back(depth + 1, i, plus, minus - 1, multi, div);
					visited[i] = 0;
				}
				else if (multi > 0) {
					visited[i] = 3;
					back(depth + 1, i, plus, minus, multi - 1, div);
					visited[i] = 0;
				}
				else if (div > 0) {
					visited[i] = 4;
					back(depth + 1, i, plus, minus, multi, div - 1);
					visited[i] = 0;
				}
			}
		}

	}

}

int calculate(int *visited) {
	int op2, cur = arr[0];
	for (int i = 0; i < N-1; i++) {
		op2 = arr[i + 1];
		switch (visited[i])
		{
		case 1: // +
			cur += op2;
			break;
		case 2: // -
			cur -= op2;
			break;
		case 3: // *
			cur *= op2;
			break;
		case 4: // /
			cur /= op2;
			break;
		default:
			break;
		}
	}
	return cur;
}