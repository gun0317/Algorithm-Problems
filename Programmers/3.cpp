#include<cstdio>
#include<map>
#include <vector>
#include <queue>
using namespace std;
map<int, long long> partSum;
queue <int> q;
int solution(vector<int> &A) {
	int len = A.size();
	int idx = 0, sum = 0, toReturn = 0;

	partSum[0]++;
	for (int i = 0; i < len; i++) {
		sum += A[i];
		toReturn += partSum[sum];
		partSum[sum]++;
		if (toReturn > 100000)
			return -1;
	}

	return toReturn;
}

int main() {
	vector <int> a;
	a.push_back(2);
	a.push_back(-2);
	a.push_back(3);
	a.push_back(3);
	a.push_back(0);
	a.push_back(4);
	a.push_back(-7);
	
	printf("%d\n", solution(a));

	return 0;
}