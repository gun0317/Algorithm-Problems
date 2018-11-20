#include <stdio.h>



int main()
{
	int N, W, gem[2][1000], i, j;

	scanf("%d %d", &N, &W);
	//cin >> N >> W;
	for (i = 0; i < N; i++)
		scanf(" %d %d", &gem[i][0], &gem[i][1]);
		//cin >> gem[i][0] >> gem[i][1];

	int dp[1010][10010];
	dp[0][0] = dp[0][1] = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < W; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (dp[i - 1][j] < dp[i - 1][j - gem[i][0]] + gem[i][1])
				dp[i][j] = dp[i - 1][j - gem[i][0]] + gem[i][1];
		}
	}


	printf("%d",dp[N][W]);
	//cout << dp[N][W];

	return 0;
}