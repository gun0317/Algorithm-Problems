#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

bool compare(string &a, string &b) {
	if (a + b > b + a) return true;
	else return false;
}

string solution2(vector<int> numbers) {
	string answer = "";
	int size = numbers.size();
	vector <string> strs;
	for (int i : numbers) strs.push_back(to_string(i));
	sort(strs.begin(), strs.end(), compare);
	for (auto i : strs) answer.append(i);
	if (answer[0] == '0')
		answer = "0";

	return answer;
}

int main() {
	vector<int> n;
	n.push_back(3);
	n.push_back(30);
	n.push_back(34);
	n.push_back(5);
	n.push_back(9);
	//n.push_back(0);
	//n.push_back(0);
	//n.push_back(0);

	printf("%s\n", solution2(n).c_str());

	return 0;
}