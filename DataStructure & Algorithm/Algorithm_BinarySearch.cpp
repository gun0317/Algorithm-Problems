#include <iostream>
using namespace std;

bool bSearch_iterative(int* list, int n, int target) {
	int left = 0, right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (list[mid] == target) return true;
		else if (list[mid] > target) right = mid - 1;
		else left = mid + 1;
	}

	return false;
}

bool bSearch_recursive(int *list, int left, int right, int target) {
	int mid = (left + right) / 2;
	if (left > right) return false;
	if (list[mid] == target) return true;
	else if (list[mid] > target) bSearch_recursive(list, left, mid - 1, target);
	else bSearch_recursive(list, mid + 1, right, target);
}

int main() {
	int list[8] = { 1,4,5,7,9,11,20,25 };
	
	cout << bSearch_iterative(list, 8, 7) << endl;
	cout << bSearch_iterative(list, 8, 8) << endl;
	cout << bSearch_recursive(list, 0, 8, 7) << endl;
	cout << bSearch_recursive(list, 0, 8, 8) << endl;

	return 0;
}