#include <iostream>
#include <string.h>
using namespace std;
///////////////////////
//Anagram algorithm////
//using backtracking///
//for combination//////
///////////////////////
string str = "abcbabbcbabcba";
int target_length = 0, ans = 0;

int check(string new_str) {
	// if possible, use kmp algorithm.
	int size = str.size();
	for (int i = 0; i < size; i++) {
		string str_to_compare = str.substr(i, target_length);
		if (strcmp(str_to_compare.c_str(), new_str.c_str()) == 0)
			ans++;
	}

	return 0;
}

void back(int depth, string new_str, string in, int alpha_avail[26]) {
	if (depth == target_length) {
		cout << new_str.c_str() << endl;
		check(new_str);
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (alpha_avail[i] == 1) {
				new_str += i + 'a';
				alpha_avail[i] = 0;
				back(depth + 1, new_str, in, alpha_avail);
				new_str.pop_back();
				alpha_avail[i] = 1;
			}
		}
	}

}

int main() {
	string in = "abc";
	target_length = in.size();
	int alpha_avail[26];
	for (int i = 0; i < target_length; i++) 
		alpha_avail[in[i] - 'a'] = 1;

	back(0, "", in, alpha_avail);
	cout << ans << endl;

	return 0;
}