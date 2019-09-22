#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[20020];

int main() {
	int n;
	cin >> n;
	int zeros = 0, max_zeros = 0, ans = 0, open_start = 0, open_end = 0;

	// closed-end cases
	for (int i = 0; i < n; i++) {
		int in;
		scanf("%d", &in);
		arr[i] = in;

		if (in == 0) 
			zeros++;
		
		else if (in == 1) {
			if (max_zeros < zeros) max_zeros = zeros;
			zeros = 0;
		}
	}
	// open-end start
	if (arr[0] == 0) {
		int cnt = 0;
		for (int i = 0; i < n; i++) 
			if (arr[i] == 0) cnt++;
		open_start = cnt;
	}


	// open-end end
	if (arr[n-1] == 0) {
		int cnt = 0;
		for (int i = n - 1; i >= 0; i--) 
			if (arr[i] == 0)cnt++;
		open_end = cnt;
	}
	vector <int> toCompare;
	toCompare.push_back(open_start);
	toCompare.push_back(open_end);
	toCompare.push_back((max_zeros - 1) / 2 + 1);
	sort(toCompare.begin(), toCompare.end(), greater<int>());
	
	cout << toCompare[0] << endl;

	return 0;
}