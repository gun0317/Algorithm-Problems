#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector <pair <int,int>> v;
int arr[5][10], visited[5], match[5], ans;

void spin(int clockwise, int index);
void spinOthers(int clockwise, int index);
void matchCheck();
void calculate();

int main() {
	int rotationCnt = 0;
	for (int cnt = 0; cnt < 4; cnt++)
		for (int i = 0; i < 8; i++)
			scanf(" %1d", &arr[cnt][i]);

	cin >> rotationCnt;
	for (int i = 0; i < rotationCnt; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a-1, b));
	}

	for (int i = 0; i < v.size(); i++) {
		matchCheck();
		for (int l = 0; l < 4; l++) visited[l] = 0;
		spin(v[i].second, v[i].first);
	}

	calculate();
	cout << ans << endl;

	return 0;
}

void calculate() {
	if (arr[0][0] == 1)ans += 1;
	if (arr[1][0] == 1)ans += 2;
	if (arr[2][0] == 1)ans += 4;
	if (arr[3][0] == 1)ans += 8;

}

void matchCheck() {
	for (int i = 0; i < 3; i++) {
		if (arr[i][2] == arr[i + 1][6])
			match[i] = 1;
		else
			match[i] = 0;
	}
}

void spin(int clockwise, int index) {
	visited[index]++;
	int temp1 = arr[index][0];
	int temp2 = arr[index][7];
	if (clockwise == -1) {
		for (int i = 0; i < 8; i++)
			arr[index][i] = arr[index][(i + 1) % 8];
		arr[index][7] = temp1;
	}

	if (clockwise == 1) {
		for(int i=7;i>=0;i--)
			arr[index][i] = arr[index][(i + 7) % 8];
		arr[index][0] = temp2;
	}

	spinOthers(clockwise, index);
}

void spinOthers(int clockwise, int index) {
	if (index - 1 >= 0) {
		if (!match[index - 1] && !visited[index - 1])
			spin(clockwise*(-1), index - 1);
	}
	if (index + 1 <= 3) {
		if (!match[index] && !visited[index + 1])
			spin(clockwise*(-1), index + 1);
	}
}
