#include <iostream>
using namespace std;

int s;

void _swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int partition(int *list, int left, int right);
void quicksort(int *list, int left, int right);
void printList(int *list);

int main() {
	int arr[] = { 5,1,3,4,2,13,5,2,3,5,16,43,3 };
	s = sizeof(arr) / sizeof(arr[0]) - 1;
	quicksort(arr, 0, s);
	for (int a : arr) printf("%d ", a);

	return 0;
}

int partition(int *list, int left, int right) {
	int pivot = list[left]; // pivot is middle one
	int low = left - 1, high = right;

	while (true) {
		while (low < right && list[low] <= pivot) low++;
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
		printList(list);
		quicksort(list, left, mid - 1);
		quicksort(list, mid + 1, right);
	}
}

void printList(int *list) {
	for (int i = 0; i <= s; i++) printf("%d ", list[i]);
	cout << endl;
}