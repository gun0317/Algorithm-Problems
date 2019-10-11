#include <iostream>
using namespace std;

void _swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int partition(int *list, int left, int right);
void quicksort(int *list, int left, int right);

int main() {
	int arr[] = { 5,1,3,4,2 };
	quicksort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	for (int a : arr) printf("%d ", a);

	return 0;
}

int partition(int *list, int left, int right) {
	int pivot = list[left], low = left + 1, high = right; // pivot is leftmost one

	while (true) {
		while (low < right && list[low] < pivot) low++;
		while (high > left && list[high] >= pivot) high--;
		if (low < high) _swap(list[low], list[high]);
		else break;
	}

	_swap(list[left], list[high]);	// high's location is where pivot should belong
	return high;
}

void quicksort(int *list, int left, int right) {
	if (left < right) {
		int mid = partition(list, left, right);
		quicksort(list, left, mid - 1);
		quicksort(list, mid + 1, right);
	}
}