#include <iostream>
using namespace std;

int s;
void _swap(int &a, int &b);
void myQsort(int *list, int left, int right);

int main() {
	int arr[] = { 14, 26, 7, 12 };
		//{ 1, 12, 5, 26, 7, 14, 3, 7, 2 };
	s = sizeof(arr) / sizeof(arr[0]) - 1;
	//quicksort(arr, 0, s);
	myQsort(arr, 0, s);
	for (int a : arr) printf("%d ", a);

	return 0;
}

void myQsort(int *list, int left, int right) {
	int cur1 = left, cur2 = right;
	int pivot = list[(left + right) / 2];

	while (cur1 <= cur2) {
		while (list[cur1] < pivot) cur1++;
		while (list[cur2] > pivot) cur2--;
		if (cur1 <= cur2) _swap(list[cur1++], list[cur2--]);
	}

	if (left < cur2) myQsort(list, left, cur2);
	if (cur1 < right) myQsort(list, cur1, right);
}

void _swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}