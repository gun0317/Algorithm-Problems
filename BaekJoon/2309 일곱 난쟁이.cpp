#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> v;

int main() {
	int h;
	for (int i = 0; i < 9; i++) {
		cin >> h;
		v.push_back(h);
	}
	sort(v.begin(), v.end());
	do {
		int sum = 0;
		for (int i = 0; i < 7; i++)	sum += v[i];
		if (sum == 100) break;

	} while (next_permutation(v.begin(), v.end()));

	sort(v.begin(), v.begin() + 7);
	for (int i = 0; i < 7; i++) cout << v[i] << endl;



	return 0;
}