#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int n, worker_num, message[10], workers[10], toProcess = 0, ans = 0;

int main() {
	cin >> n >> worker_num;
	for (int i = 0; i < n; i++) 
		cin >> message[i];
	   
	int endFlag = 0;
	while(true) {
		if(toProcess < n)
			for (int w = 0; w < worker_num; w++) {
				if (workers[w] == 0)
					workers[w] = message[toProcess++];
			}
		sort(workers, workers + worker_num);
		int minTimeLeft = workers[0], minTimeIdx = 1, workIdx = 0;
		while (minTimeLeft == 0) {
			if (minTimeIdx == worker_num) {
				endFlag++;
				break;
			}
			minTimeLeft = workers[minTimeIdx++];
			workIdx = minTimeIdx - 1;
		}
		if (endFlag) break;
		for (int w = workIdx; w < worker_num; w++)
				workers[w] -= minTimeLeft;
		ans += minTimeLeft;
	}

	cout << ans << endl;


	return 0;
}