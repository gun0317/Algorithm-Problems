#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
	int answer = 0;
	stack <char> par;
	const char *cur = arrangement.c_str();
	
	while (*cur != '\0') {
		// stack push case
		if (*cur == '(' && *(cur + 1) == '(') {
			par.push(*cur);
			answer++;
		}
		// stack pop case
		else if (*cur == ')' && *(cur - 1) == ')')
			par.pop();
		// lazer case
		else if (*cur == '(' && *(cur + 1) == ')')
			answer += par.size();
		// move the pointer
		cur++;
	}

	return answer;
}

int main() {
	printf("ans: %d", solution("()(((()())(())()))(())"));

	return 0;
}