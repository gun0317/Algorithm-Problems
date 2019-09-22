#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int accum[200];

int main(void) {
	int n;
	cin >> n;
	vector <pair <int, int>> times;	// first: out time, second: in time
	for (int i = 0; i < n; i++) {
		int in, out;
		scanf("%d %d", &in, &out);
		times.push_back({ out,in });
	}
	sort(times.begin(), times.end());
	int endTime = 0, cnt = 1, ans = 0;
	for (int i = 0; i < n - 1; i++) { // TODO: range check
		endTime = times[i].first;
		cnt = 1;
		for (int j = i + 1; j < n; j++) 
			if (endTime > times[j].second) 
				cnt++;
			else 
				break;
		
		if (ans < cnt) ans = cnt;
	}
	cout << ans << endl;
	return 0;
}