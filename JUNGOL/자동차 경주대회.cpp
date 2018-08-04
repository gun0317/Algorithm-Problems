#include <iostream>
#define MAX 1000000
using namespace std;


int visit[100];


//*************************��ΰ� �ʿ��Ҷ�:
//visit�� '�� ������ �ִܽð����� ���������� �������ϴ� ��������'�� ����
//visit�� ����Ȱ� backtracking. cnt�� ���� ������Ų��.
void path(int N, int cnt)	//���⼭ N = �湮����.
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
	//�Է�, �ʱ�ȭ
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
	//�Է�, �ʱ�ȭ ��

	int idx = 0;
	//dp[i] = min{ time[i] + dp[i���� 140�Ÿ����� �ִ¾ֵ� index] }
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
	
	//dp�ϼ�, dp[N+1]�� ���������� �ִ� ���� �ð�, visit[]�� ���� �湮 ����

	if (!visit[N])
		cout << "0" << endl;
	else
	{
		cout << dp[N + 1] << endl;
		path(visit[N], 0);
	}
	
	

	return 0;
}