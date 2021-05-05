#include <iostream>
using namespace std;

int zeros, ones, minuses;
int **arr;

int check(int x, int y, int mx, int my)
{
	int i, j;
	int start = arr[x][y];
	for (i = x; i < mx; i++)
		for (j = y; j < my; j++)
			if (arr[i][j] != start)
				return false;
	return true;
}

int DnC(int **arr, int x, int y, int mx, int my)
{
	int temp = arr[start][start];
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			if (temp != arr[start + i][start + j])
			{
				if()
				for (int k = 0; k < 9; k++)
					DnC(arr, N / 3, start + N/9);
			}
		}
}


int main()
{
	int i , j, N;
	cin >> N;
	arr = new int*[N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[N];

	for (i = 0; i < N; i++)
		for (j = 0; i < N; j++)
			cin >> arr[i][j];








	for (int i = 0; i < N; i++)
		delete(arr[i]);
	delete(arr);

	return 0;
}


