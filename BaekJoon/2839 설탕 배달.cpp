#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int fives = N / 5;
	while (fives >= 0) {
		int temp = N - 5 * fives;
		if (temp % 3 == 0) {
			cout << fives + temp / 3 << endl;
			return 0;
		}
		else {
			fives -= 1;
		}
	}
	cout << -1 << endl;
	return 0;
}