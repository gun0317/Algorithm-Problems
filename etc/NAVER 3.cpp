#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int pre_size = 0, visited[1010];
int pre[1010] = { 0 }, prec[1010];
vector <int> suc[1010], savedPre[1010];

int preNum(int cur) {
	visited[cur] ++;
	int toReturn = 0;
	for (int now : savedPre[cur]) {
		if(!visited[now])
			toReturn += preNum(now);
	}

	return toReturn + 1;
}

vector <int> solution(vector<int> cook_times, vector<vector<int>> order, int k) {
	vector<int> answer;
	int N = cook_times.size();
	int K = order.size();

	for (int i = 0; i < K; i++) {
		int x = order[i][0];
		int y = order[i][1];
		suc[x - 1].push_back(y - 1);
		pre[y - 1]++;
		prec[y - 1]++;
		savedPre[y].push_back(x);
	}
	int result[1010] = { 0 };
	queue<int> q;
	for (int i = 0; i < N; i++)
		if (!pre[i]) q.push(i);

	while (pre[k - 1] > 0) {
		int cur = q.front();
		q.pop();
		for (int it : suc[cur]) {
			result[it] = max(result[it], result[cur] + cook_times[cur]);
			if (--pre[it] == 0) q.push(it);
		}
	}

	pre_size = preNum(k);
	answer.push_back(pre_size - 1);
	answer.push_back(result[k-1] + cook_times[k-1]);
	
	return answer;
}

int main() {
	vector <int> c,temp;
	c.push_back(5);
	c.push_back(3);
	c.push_back(2);

	vector <vector<int>> o;
	temp.push_back(1);
	temp.push_back(2);
	o.push_back(temp);
	temp.clear();
	temp.push_back(2);
	temp.push_back(3);
	o.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(3);
	o.push_back(temp);
	int k = 3;
	
	vector <int> sol;
	sol = solution(c, o, k);
	for (int i = 0; i < sol.size(); i++)
		printf("%d ", sol[i]);


	return 0;
}