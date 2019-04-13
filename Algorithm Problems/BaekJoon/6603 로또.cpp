#include <iostream>
#include <cstdio>
using namespace std;
int visited[10];
int arr[14];
int k;

void back(int depth, int cur);
int main() {
	while (1) {
		cin >> k; if (k == 0) break;
		for (int i = 0; i < k; i++) {
			int temp; scanf(" %d",&temp);
			arr[i] = temp;
		}
		back(0, 0);
		cout << endl;

	}


	return 0;
}

void back(int depth, int cur) {
	if (depth == 6) {
		for (int i = 0; i < k; i++)
			if (visited[i]) printf("%d ",arr[i]);
		printf("\n");
		return;
	}
	else {
		for(int i=cur;i<k;i++)
			if (!visited[i]) {
			visited[i]++;
			back(depth + 1, 1+i);
			visited[i]--;
			}
	}
}