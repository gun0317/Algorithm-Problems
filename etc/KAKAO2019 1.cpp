#include <string>
#include <vector>
#include <iostream>
using namespace std;

int intlen(int a) {
	if (a == 1000) return 4;
	else if (a >= 100) return 3;
	else if (a >= 10) return 2;
	else if (a >= 2) return 1;
	else return 0;
}

int solution(string s) {
	int answer = 1001;
	int s_len = s.length();
	if (s_len == 1)
		return 1;

	for (int subStrLen = 1; subStrLen <= s_len / 2; subStrLen++) {
		//cout << subStrLen << endl;
		int startIdx = 0;
		int localAns = 0;
		while (startIdx + subStrLen <= s_len) {
			//cout << startIdx << "+" << subStrLen << "<=" << s_len<<endl;
			string subStr = s.substr(startIdx, subStrLen);
			int subStartIdx = startIdx;
			int subLocalAns = 0;
			while (subStartIdx + subStrLen <= s_len) {
				//cout << subStartIdx << "+" << subStrLen << "<=" << s_len << endl;
				string cmp = s.substr(subStartIdx, subStrLen);
				if (subStr.compare(cmp) == 0) {
					subLocalAns++;
					subStartIdx += subStrLen;
				}
				else {
					break;
				}
			}
			startIdx = subStartIdx;
			localAns += intlen(subLocalAns) + subStrLen;
		}
		localAns += s_len - startIdx;
		answer = answer > localAns ? localAns : answer;
	}
	return answer;
}

int main() {
	string s = "abcabcabcabcdededededede";
	cout << solution(s) << endl;

	return 0;
}