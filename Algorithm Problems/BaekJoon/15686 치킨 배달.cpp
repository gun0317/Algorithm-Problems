#include <iostream>
#include <vector>
#include <algorithm>
#define pairType pair <int,int> 
using namespace std;
vector <pairType> house;
vector <pairType> chicken;
int N, M, houseCnt, chikenCnt;
int map[60][60], allDist[200][200], visited[14];
int minimum;
int calDist();
void back(int depth, int cur);

int main() {
	// getting input
	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int temp = -1;
			cin >> temp;
			map[r][c] = temp;
			switch (temp)
			{
			case 1:
				house.push_back(make_pair(r, c));
				houseCnt++;
				break;
			case 2:
				chicken.push_back(make_pair(r, c));
				chikenCnt++;
				break;
			default:
				break;
			}
		}
	}
	
	// calculate all possible distances from all houses to all chicken store
	for (int h = 0; h < houseCnt; h++) {
		for (int c = 0; c < chikenCnt; c++) {
			allDist[c][h] = abs(house[h].first - chicken[c].first) + abs(house[h].second - chicken[c].second);
		}
	}


	minimum = 99999999999999;
	// back track to find the answer 
	back(0, 0);
	cout << minimum << endl;

	return 0;
}

int calDist() {
	int totalDist = 0;

	for (int h = 0; h < houseCnt; h++) {
		int curMin = 9999999999999999;
		for (int c = 0; c < chikenCnt; c++) {
			if (visited[c] == 1 && curMin > allDist[c][h]) {
				curMin = allDist[c][h];
			}
		}
		totalDist += curMin;
	}

	return totalDist;
}


void back(int depth, int cur) {
	// combination completed
	if (depth == M) {
		int curDist = calDist();
		if (minimum > curDist) {
			minimum = curDist;
		}
		return;
	}

	// new combination needed
	else {
		for (cur; cur < chikenCnt; cur++) {
			if (visited[cur] == 0) {
				visited[cur] = 1;
				back(depth + 1, cur+1);
				visited[cur] -= 1;
			}
		}
	}
}
