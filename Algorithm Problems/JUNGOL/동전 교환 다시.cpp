#include <iostream>
#define MAX 99999
using namespace std;

int main()
{

	//getting input
	int N, W, i, j;
	int coins[15];
	cin >> N;
	for (i = 0; i < N; i++) cin >> coins[i];
	cin >> W;
	//

	//initialize dp
	int dp[64001];
	for (i = 0; i < W+1; i++) dp[i] = MAX;
	dp[0] = 1;
	for (i = 0; i < N; i++)	dp[coins[i]] = 1;
	//

	//completing dp
	//dp[i] = min(dp[i-coins[j]) , j = 0,1,2 ... N-1
	for (i = 1; i < W+1; i++)
		for (j = 0; j < N; j++)
			if(i-coins[j] > 0)
				if ((dp[i - coins[j]]+1)<dp[i])	dp[i] = dp[i - coins[j]] + 1;
	//

	if (dp[W] == MAX)
		cout << "impossible" << endl;
	else
		cout << dp[W] << endl;

	return 0;

}