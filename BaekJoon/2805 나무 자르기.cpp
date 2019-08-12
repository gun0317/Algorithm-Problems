#include <iostream>
using namespace std;

long N, M, trees[1000010], ans, maxHeight = 0;

long cutTrees(int height) {
	long toReturn = 0;
	for (int i = 0; i < N; i++) {
		long localLen = trees[i] - height;
		if (localLen > 0) toReturn += localLen;
	}
	return toReturn;
}

void bSearch() {
	long left = 0, right = maxHeight - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		long local = cutTrees(mid);
		if (cutTrees(mid) >= M) {
			left = mid + 1;
			if (ans < mid) ans = mid;
		}
		else 
			right = mid - 1;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
		if (maxHeight < trees[i]) maxHeight = trees[i];
	}
	bSearch();
	cout << ans << endl;

	return 0;
}