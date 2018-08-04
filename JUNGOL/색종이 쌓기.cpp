#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const pair<int,int>& a, const pair<int,int>& b)
{
	return a.first > b.first;
}
int main()
{
	
	int i, j, N;
	cin >> N;
	int Area[100];
	
	vector <pair<int, int>> papers;
	vector <pair<int, int>>::iterator itor;
	vector <pair<int, int>>::iterator itor2;
	int idx = 0;
	itor = papers.begin();
	for (i = 0; i < N; i++)
	{
		int a, b, temp;
		cin >> a >> b;
		temp = min(a, b);
		a = max(a, b);
		b = temp;
		papers.push_back(make_pair(a, b));
	}
	sort(papers.begin(), papers.end(),compare);
	int index=0;
	int ans=0;
	i = 0;
    	while (1)
	{
		if (papers.size() == 1)
			break;
		int cnt[100] = { 0 };
		i = 0;
		for (itor = papers.begin(); itor < papers.end(); itor++)
		{
			for (itor2 = itor + 1; itor2 < papers.end(); itor2++)
			{
				if((*itor).second>=(*itor2).second)
					cnt[i]++;
			}
			i++;
		}

		int max = cnt[0];
		for (i = 0; i < N-ans; i++)
		{
			if (max <= cnt[i])
			{
				max = cnt[i];
				index = i;
			}
		}
		if (index == 0)
			papers.erase(papers.begin());
		else
			papers.erase(papers.begin(),papers.begin() +1+ index);
		ans++;
	}

	cout << ++ans << endl;
	return 0;
}