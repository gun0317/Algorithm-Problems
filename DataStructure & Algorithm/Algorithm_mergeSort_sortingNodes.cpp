#define MAX_NODES 500000
#include <iostream>
using namespace std;
/////////////////////////////////
//sorting with multiple columns//
/////////////////////////////////
typedef struct grade {
	// score: bigger the better, rating: smaller the better. **rating comes first**
	int score, rating;
}grade;

int compare(grade &a, grade &b) {
	if (a.rating != b.rating) return -(a.rating - b.rating);	// the smaller the better
	return a.score - b.score;	// the bigger the better
}

grade sorted[MAX_NODES];
void merge(grade* list, int left, int right) {
	int mid = (left + right) / 2;
	int first = left, second = mid + 1, idx = left;
	while (left <= mid && second <= right)
		if (compare(list[first], list[second]) > 0) sorted[idx++] = list[first++];
		else sorted[idx++] = list[second++];
	if (first <= mid)
		for (int i = first; i <= mid; i++) sorted[idx++] = list[i];
	if (second <= right)
		for (int i = second; i <= right; i++) sorted[idx++] = list[i];
	for (int i = left; i <= right; i++) list[i] = sorted[i];
}

void mergeSort(grade* list, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(list, left, mid);
		mergeSort(list, mid + 1, right);
		merge(list, left, right);
	}
}

void printList(grade* arr) {
	for (int i = 0; i < 5; i++) {
		printf("arr[%d] - rating: %d, score: %d\n", i, arr[i].rating, arr[i].score);
	}
}

int main() {
	grade arr[5];
	arr[0].rating = 5, arr[0].score = 32;
	arr[1].rating = 3, arr[1].score = 56;
	arr[2].rating = 1, arr[2].score = 99;
	arr[3].rating = 3, arr[3].score = 52;
	arr[4].rating = 1, arr[4].score = 100;
	printList(arr);
	mergeSort(arr, 0, 4);
	cout << "SORTED" << endl;
	printList(arr);



	return 0;
}