#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
	vector <int> candidates;
	int localTurbulence = 2, curHeight = 0, len = A.size(), up = 0, toReturn = 0;
	if (len == 1) return 1;
	curHeight = A[1];
	if (A[1] - A[0] > 0) up = 1;
	else if (A[1] - A[0] < 0) up = -1;
	else if (A[1] == A[0]) {
		up = 0;
		localTurbulence = 1;
	}

	for (int i = 2; i < len; i++) {
		int diff = A[i] - curHeight;
		if (diff < 0) {
			if (up == 1 || up == 0) {
				localTurbulence++;
			}
			else if (up == -1) {
				if (toReturn < localTurbulence)
					toReturn = localTurbulence;
				localTurbulence = 2;
			}
			up = -1;
		}
		else if (diff > 0) {
			if (up == -1 || up == 0) {
				localTurbulence++;
			}
			else if (up == 1) {
				if (toReturn < localTurbulence)
					toReturn = localTurbulence;
				localTurbulence = 2;
			}
			up = 1;
		}
		else if (A[i] == curHeight) {
			if (toReturn < localTurbulence)
				toReturn = localTurbulence;
			localTurbulence = 1;
			up = 0;
		}

		curHeight = A[i];
	}
	if (toReturn < localTurbulence)
		toReturn = localTurbulence;

	return toReturn;
}


int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(1);
	a.push_back(2);
	//a.push_back(7);
	//a.push_back(8);
	//a.push_back(8);
	//a.push_back(1);
	//a.push_back(9);
	cout << solution(a) << endl;

	return 0;
}