#include <iostream>
using namespace std;

char arr[110][110];
int main()
{
	int N, i, j, garo = 0, sero = 0;
	cin >> N;
	char temp = '\n';
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> arr[i][j];
	
	
	for (i = 0; i < N; i++)
	{
		temp = arr[i][0];
		for (j = 1; j < N; j++)
		{
			if (temp == arr[i][j] && temp != 'X')
			{
				garo++;
				while (temp == arr[i][j])
					j++;
			}
			temp = arr[i][j];
		}
	}

	for (i = 0; i < N; i++)
	{
		temp = arr[0][i];
		for (j = 1; j < N; j++)
		{
			if (temp == arr[j][i] && temp != 'X')
			{
				sero++;
				while (temp == arr[j][i])
					j++;
			}
			temp = arr[j][i];
		}
	}


	cout << garo << " " << sero << endl;
	return 0;
}