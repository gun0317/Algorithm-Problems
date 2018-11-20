#include <iostream>
#define MAX 1000000
using namespace std;


int visit[100];


//*************************경로가 필요할때:
//visit에 '각 지점에 최단시간으로 도달했을때 지나야하는 이전지점'을 저장
//visit에 저장된걸 backtracking. cnt도 같이 증가시킨다.
void path(int N, int cnt)	//여기서 N = 방문지점.
{
	if (N == 0)
	{
		cout << cnt << endl;
		return;
	}
	else
	{
		path(visit[N-1], cnt + 1);
		printf("%d ", N);
	}
}

int main()
{
	//입력, 초기화
	int maxDist, i, j, k;
	int distance[101] = { 0 };
	int time[102] = { 0 };
	int dp[101] = { 0, };
	cin >> maxDist;
	int N;
	cin >> N;
	for (i = 1; i < N + 2; i++)
		dp[i] = MAX;
	for (i = 1; i < N + 2; i++)
	{
		cin >> distance[i];
		distance[i] += distance[i - 1];
	}
	distance[N + 2] = 0;
	for (i = 1; i < 1 + N; i++)
		cin >> time[i];
	time[N + 1] = 0;
	dp[0] = 0;
	//입력, 초기화 끝

	int idx = 0;
	//dp[i] = min{ time[i] + dp[i에서 140거리내에 있는애들 index] }
	for (i = 1; i < N + 2; i++)
	{
		for (k = i - 1; k >= 0; k--)
			if (distance[i] - distance[k] <= maxDist)
				if (dp[i] > time[i] + dp[k])
				{
					dp[i] = time[i] + dp[k];
					visit[idx] = k;
				}
		idx++;
	}
	
	//dp완성, dp[N+1]에 목적지까지 최단 정비 시간, visit[]에 이전 방문 지점

	if (!visit[N])
		cout << "0" << endl;
	else
	{
		cout << dp[N + 1] << endl;
		path(visit[N], 0);
	}
	
	

	return 0;
}