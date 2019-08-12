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
	int cur1 = left, cur2 = mid + 1 , idx = left;
	// merge til one side's end // 내림차순
	while (cur1 <= mid && cur2 <= right) 
		if (list[cur1] < list[cur2]) sorted[idx++] = list[cur1++];
		else sorted[idx++] = list[cur2++];
	// if one side's end came prior to another one
	if (cur1 <= mid)
		for (int i = cur1; i <= mid; i++) sorted[idx++] = list[i];
	else for (int i = cur2; i <= right; i++) sorted[idx++] = list[i];
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