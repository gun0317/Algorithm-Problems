#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
vector <int> map[110];
vector <int> endPoint(110,0);
bool ans[110];

int main() {
	int N, max = 0;
	cin >> N;
	cin.ignore();
	for (int i = 1; i <= N; i++) {
		char line[110];
		cin.getline(line, 110);
		stringstream strS(line);

		int fork = 0;
		for (; !(strS >> fork).fail();) {
			map[fork].push_back(i);
		}
		endPoint[i] = fork;
		if (fork > max) max = fork;
	}

	int cnt = 0;
	
	for (int i = 1; i <= N; i++) {
		// 
		int candidate = endPoint[i];
		vector <int> temp = map[candidate];
		int flag = 0;
		for (int j = 0; j < temp.size(); j++) {
			sort(temp.begin(), temp.end());
			// endPoint[temp내의원소 첫 번째] == endPoint[temp내의 마지막 원소] == candidate이면 ok
			if (endPoint[temp[temp.size() - 1]] == candidate && endPoint[temp[temp.size() - 1]] == endPoint[temp[0]]) {
				ans[candidate] = true;
			}
				
		}
	}

	for (int i = 1; i <= max; i++) {
		if (ans[i]) cout << i << " ";
	}
	cout << endl;


	return 0;
}
/*
8
1 2 4 7
3 4 7 9
5 8 9
6 8
10 12 14
11 12 14 17
15 17
13 16 17


*/