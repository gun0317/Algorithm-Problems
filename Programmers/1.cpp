#include <iostream>
#include <vector>
using namespace std;
int visited[100010];

int solution(vector<int> &A) {
	int toReturn = 0, turnedOn = -1, waiting = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] - 1 == turnedOn + 1) {
			int idx = turnedOn + 1;
			visited[idx]++;
			while (visited[++idx] == 1);
			idx--;
			turnedOn = idx;
			toReturn++;
		}
		else if (A[i] - 1 != turnedOn) {
			visited[A[i] - 1]++;
		}
	}

	return toReturn;
}

int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(4);
	a.push_back(2);
	a.push_back(5);
	cout << solution(a) << endl;

	return 0;
}