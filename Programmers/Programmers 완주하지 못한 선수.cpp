#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map <string, int> completed;
string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	for (auto names : completion) {
		if (completed[names] > 0)
			completed[names]++;
		else completed[names] = 1;
	}
	for (auto names : participant) {
		if (completed.find(names) == completed.end() || completed[names] == 0) {
			answer += names;
		}
		if (completed.find(names) != completed.end() && completed[names] > 0) {
			completed[names]--;
		}

	}
	return answer;
}