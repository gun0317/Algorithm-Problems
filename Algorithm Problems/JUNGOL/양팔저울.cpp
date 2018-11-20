#include <iostream>
#include <stdio.h>
using namespace std;


int main()
{
	int chuN, ballN, i, j, chu[40], ball[10];
	cin >> chuN;
	for (i = 1; i <= chuN; i++)
		cin >> chu[i];
	cin >> ballN;
	for (i = 1; i <= ballN; i++)
		cin >> ball[i];

	int dp[40][40010] = { 0 };
	dp[0][0] = 1;
	for (i = 1; i <= chuN; i++)
	{
		dp[i][chu[i]] = 1;
		for (j = 1; j <= 40000; j++)
		{
			if (dp[i - 1][j] == 1)
			{
				dp[i][j] = 1;
				dp[i][j + chu[i]] = 1;
				dp[i][abs(j - chu[i])] = 1;			
			}
		}
	}

	for (i = 1; i <= ballN; i++)
		printf("%c ", (dp[chuN][ball[i]] == 1) ? ('Y') : ('N'));
	return 0;
}
