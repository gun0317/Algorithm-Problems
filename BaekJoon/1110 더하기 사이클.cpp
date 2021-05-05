#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int cnt = 1;
	int cur = N;
	while (1)
	{
		int first = cur % 10;
		int second = (cur % 10 + cur / 10)%10;
		first *= 10;
		cur = first + second;
		if (N == cur)
			break;
		cnt++;
	}


	cout << cnt << endl;
	return 0;
}