#include <iostream>
#include <cmath>
using namespace std;

double numLength(long int n)
{
	double l=0;
	while (1)
	{
		if (n < pow(10, l++))
			break;
	}
	return l;
}

int digit(long int num, double p)
{
	//cout <<"digit"<< (int)((num / pow(10, p - 1))) << endl << (int)(num / pow(10, p)) * 10<<endl;
	return (int)((num / pow(10, p - 1)) - (int)(num / pow(10, p)) * 10);
}

int main()
{
	long  N, i, j;
	cin >> N;
	if (N == 1)
	{		
		cout << "2" << endl;
		return 0;
	}
	while (1)
	{
		int flag = 1;
		//Prime num check
		for (i = 2; i <= sqrt(N); i++)
			if (N%i == 0)
			{
				flag--;
				break;
			}
		if (flag == 0)
		{
			N++;
			continue;
		}
		//

		//palindrome check
		double len = numLength(N);
		len--;
		for (double k = 1; k <= len / 2; k++)
		{
			int d1 = digit(N, k);
			int d2 = digit(N, len - k + 1);
			if (d1 != d2)
			{
				flag--;
				break;
			}
		}

		if (flag == 1)
		{
			cout << N << endl;
			return 0;
		}

		N++;
		

	}

	return 0;
}