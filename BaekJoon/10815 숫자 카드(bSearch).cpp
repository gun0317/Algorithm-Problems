#define MAX_CARDS 500010
#include <iostream>
using namespace std;

int N, M, have[MAX_CARDS], sorted[MAX_CARDS];

void merge(int* list, int left, int right) {
	int mid = (left + right) / 2;
	int first = left, second = mid + 1, sortedIdx = left;
	while (first <= mid && second <= right) 
		if (list[first] < list[second]) sorted[sortedIdx++] = list[first++];
		else sorted[sortedIdx++] = list[second++];
	if (first <= mid)
		for (int i = first; i <= mid; i++) sorted[sortedIdx++] = list[i];
	else if (second <= right)
		for (int i = second; i <= right; i++) sorted[sortedIdx++] = list[i];
	for (int i = left; i <= right; i++) list[i] = sorted[i];
}

void mergeSort(int* list, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(list, left, mid);
		mergeSort(list, mid + 1, right);
		merge(list, left, right);
	}
}
// iterative binary search
int bSearch(int* list, int len, int target) {
	int left = 0, right = len - 1, mid = (left + right) / 2;
	while (left <= right) {
		mid = (left + right) / 2;
		if (list[mid] == target) return 1;
		else if (list[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) 
		scanf(" %d", &have[i]);
	mergeSort(have, 0, N - 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		scanf(" %d", &temp);
		printf("%d ", bSearch(have, N, temp));
	}
	cout << endl;
	return 0;
}