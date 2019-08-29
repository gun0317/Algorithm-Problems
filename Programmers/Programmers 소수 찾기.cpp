#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int visited[10000000];

bool isPrime(int n) {
	if (visited[n]) return false;
	else visited[n]++;
	if (n == 1 || n == 0) return false;
	for (int i = 2; i*i <= n; i++)
		if (n % i == 0) return false;
	printf("primeNum: %d\n", n);
	return true;
}

int solution(string numbers) {
	int answer = 0;
	int size = strlen(numbers.c_str());
	vector <int> numInt;
	for (int i = 0; i < size; i++) numInt.push_back(numbers[i] - '0');
	 
	do {
		for (int s = 0; s < size; s++) {
			int curNum = 0;
			for (int i = 0; i <= s; i++) {
				curNum *= 10;
				curNum += numInt[i];
			}
			if (isPrime(curNum)) answer++;
		}
	} while (next_permutation(numInt.begin(), numInt.end()));

	return answer;
}

int main() {
	string n = "213123";
	printf("%d\n", solution(n));

	return 0;
}