#include <string>
#include <vector>
#include <stack>
using namespace std;
int t, answer = 0;

int cal(int* combi, int size, vector<int> numbers) {
	int toReturn = 0;
	for (int i = 0; i < size; i++) 
		toReturn += numbers[i] * combi[i];

	return toReturn;
}

void back(int* combi, int depth, int targetDepth, vector<int> numbers, int target) {
	if (depth == targetDepth) {
		if (cal(combi, targetDepth, numbers) == target) 
			answer++;
		return;
	}
	else {
		combi[depth] = 1;
		back(combi, depth + 1, targetDepth, numbers, target);
		combi[depth] = -1;
		back(combi, depth + 1, targetDepth, numbers, target);
		combi[depth] = 0;
	}
}

int solution(vector<int> numbers, int target) {
	int size = numbers.size();
	int *combi = new int[size];
	back(combi, 0, size, numbers, target);

	return answer;
}

int main() {
	vector<int> n;
	t = 3;
	n.push_back(1);
	n.push_back(1);
	n.push_back(1);
	n.push_back(1);
	n.push_back(1);
	printf("%d\n", solution(n, t));


	return 0;
}