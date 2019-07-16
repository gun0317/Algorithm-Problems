#define MAX_SIZE 100
#include <iostream>
using namespace std;

void printList(int* list) {
	printf("Printing list: ");
	for (int i = 0; i < 8; i++) printf("%d ", list[i]);
	cout << endl;
}

void merge(int* list, int left, int right) {
	int sorted[MAX_SIZE], mid = (left + right) / 2;
	int first = left, second = mid + 1 , idx = left;
	// merge til one side's end // 내림차순
	while (first <= mid && second <= right) 
		if (list[first] < list[second]) sorted[idx++] = list[first++];
		else sorted[idx++] = list[second++];
	// if one side's end came prior to another one
	if (first <= mid)
		for (int i = first; i <= mid; i++) sorted[idx++] = list[i];
	else for (int i = second; i <= right; i++) sorted[idx++] = list[i];
	//copying
	for (int i = left; i <= right; i++) list[i] = sorted[i];
}

void mergeSort(int* list, int left, int right) {
	if (left < right) {	// <? <=?
		int mid = (left + right) / 2;
		mergeSort(list, left, mid);
		mergeSort(list, mid + 1, right);
		merge(list, left, right);
		printList(list);
	}
}

int main() {
	int list[8] = { 4, 3, 14, 6, 1, 9, 11, 12 };
	int len = 8;
	printList(list);
	mergeSort(list, 0, sizeof(list)/sizeof(list[0])-1);
	printList(list);
	return 0;
}