#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void) {
	int a, b, c, target;
	cin >> a >> b >> c;
	cin >> target;
	vector <int> arr;
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	sort(arr.begin(), arr.end());
	int idx = 0, ans = 0;
	do {
		if (idx == target) break;
		ans = arr[0] * 100 + arr[1] * 10 + arr[2];
		idx++;
	} while (next_permutation(arr.begin(), arr.end()));

	cout << ans << endl;

	return 0;
}