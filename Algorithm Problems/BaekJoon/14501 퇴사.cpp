#include <iostream>
#include <vector>
using namespace std;
int N, time[16], price[16], visit[16], ans;
vector <int> v;
void back(int cur, int cnt);

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> time[i] >> price[i];
		// impossible customers
		if (i + time[i] > N + 1)
			price[i] = 0;
	}

	back(1, 0);
	cout << ans << endl;

	return 0;
}

void back(int cur, int cnt) {
	if (cur > N) {
		int localPrice = 0;
		for (int i = 0; i < cnt; i++)
			localPrice += price[v[i]];
		if (localPrice > ans) ans = localPrice;

		return;
	}
	else {
		for (; cur <= N; cur++) {
			if (!visit[cur]) {
				visit[cur] = 1;
				v.push_back(cur);
				back(cur + time[cur], cnt+1);
				visit[cur] = 0;
				v.pop_back();
			}
		}
	}

}
