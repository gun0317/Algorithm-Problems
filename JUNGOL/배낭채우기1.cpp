#include <iostream>
using namespace std;

int jam[1000] = { 0, };
int price[1000] = { 0,};
int main()
{
	int N, W;
	cin >> N >> W;
	int i, j, k;
	for (i = 0; i < N; i++)
		cin >> jam[i] >> price[i];
	int dp[10000];

	//dp의 초기값 설정
	for (i = 0; i < W; i++) dp[i] = 0;
	for (i = 0; i < N; i++) dp[jam[i]] = price[i];
	//

	//dp 채우기
	//점화식 -> dp[w] = max{dp[w-jam[i]]+price[i]}, i=0,1,..N
	for (i = 1; i < 1+W; i++)
		for (j = 0; j < N; j++)
			if (i - jam[j] >= 0)
				if (dp[i] < dp[i - jam[j]] + price[j]) 
					dp[i] = dp[i - jam[j]] + price[j];

	cout << dp[W] << endl;

	return 0;
}