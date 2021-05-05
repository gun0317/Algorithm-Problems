#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <pair<int, char> > card;
	int i, j;
	char t;
	for (i = 0; i < 5; i++) {
		cin >> t >> j;
		card.push_back(make_pair(j, t));
	}
	sort(card.begin(), card.end());
	
	int sameColor = 0;
	int sameNum = 0;
	int consecNum = 0;
	for (i = 0; i < 4; i++)
	{
		if (card[i].second == card[i + 1].second)
			sameColor++;
		if (card[i].first + 1 == card[i + 1].first)
			consecNum++;
		if (card[i].first == card[i + 1].first)
			sameNum++;
	}

	return 0;
}