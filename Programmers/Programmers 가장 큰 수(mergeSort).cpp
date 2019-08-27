#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int sorted[100010];
void merge(int *list, int left, int right) {
	int mid = (left + right) / 2, idx = left;
	int cur1 = left, cur2 = mid + 1;
	while (cur1 <= mid && cur2 <= right) {
		string cur1str = to_string(list[cur1]);
		string cur2str = to_string(list[cur2]);
		string cur1cur2 = cur1str + cur2str;
		string cur2cur1 = cur2str + cur1str;
		if (stoi(cur1cur2) > stoi(cur2cur1))
			sorted[idx++] = list[cur1++];
		else
			sorted[idx++] = list[cur2++];
	}

	if (cur1 <= mid)
		for (int i = cur1; i <= mid; i++) sorted[idx++] = list[i];
	else if (cur2 <= right)
		for (int i = cur2; i <= right; i++) sorted[idx++] = list[i];

	for (int i = left; i <= right; i++) list[i] = sorted[i];
}

void mergeSort(int *list, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(list, left, mid);
		mergeSort(list, mid + 1, right);
		merge(list, left, right);
	}
}


string solution(vector<int> numbers) {
	string answer = "";
	int size = numbers.size();
	int *arr = new int[size];
	for (int i = 0; i < size; i++) arr[i] = numbers[i];
	mergeSort(arr, 0, size - 1);

	for (int i = 0; i < size; i++)
		if (i == 0 && arr[i] == 0) {
			answer = "0";
			break;
		}
		else
			answer.append(to_string(arr[i]));
	
	return answer;
}



int main() {
	vector<int> n;
	n.push_back(3);
	n.push_back(30);
	n.push_back(34);
	n.push_back(5);
	n.push_back(9);
	//n.push_back(0);
	//n.push_back(0);
	//n.push_back(0);

	printf("%s\n", solution(n).c_str());

	return 0;
}