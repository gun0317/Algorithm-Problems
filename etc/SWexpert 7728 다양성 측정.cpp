#include<iostream>
#include <math.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, ans = 0, hash[11];
		for (int i = 0; i < 10; i++)
			hash[i] = 0;
		cin >> N;
		int len = 0;
		int temp = N;
		while (temp > 0) {
			hash[temp % 10] = 1;
			temp /= 10;
			len++;
		}
		for (int i = 0; i <10; i++) 
			if (hash[i] > 0) ans++;

		printf("#%d %d\n", test_case,ans);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}