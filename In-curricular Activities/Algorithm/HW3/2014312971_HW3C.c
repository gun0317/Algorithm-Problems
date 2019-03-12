//2014312971 ÀÌ¿µ°Ç
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int state(char element);
void NumOfChanges(char *arr, double **dp, int N);


int main(void)
{
	char arr[51] = { 0, };
	int N,i=0;

	scanf("%[^\n]s", arr);
	N = strlen(arr);

	//making 2-D dynamic allocatd double array 'dp'.
	double **dp;
	dp = (double**)malloc(sizeof(double) * N);
	dp[0] = (double*)malloc(sizeof(double) * N * 2);
	for (i = 1; i < N; i++)
		dp[i] = dp[i - 1] + 2;

	NumOfChanges(arr, dp, N);


	//freeing the memory.
	free(dp[0]);
	free(dp);

	return 0;
}


int state(char element)
{
	return element - '0';
}

void NumOfChanges(char *arr, double **dp, int N)
{
	int last,i;
	last =	state(arr[N - 1]);

	//setting base condition.
	dp[N - 1][last] = 0;
	dp[N - 1][!last] = 1;

	//setting the values that are not in base condition.
	for (i = N - 2; i > -1; i--)
	{
		if (state(arr[i]))
		{
			dp[i][0] = dp[i + 1][1] + pow(2, N - 1 - i);
			dp[i][1] = dp[i + 1][0];
		}
		else
		{
			dp[i][0] = dp[i + 1][0];
			dp[i][1] = dp[i + 1][1] + pow(2, N - 1 - i);
		}

	}


	printf("%0.0f", dp[0][0]);



}
