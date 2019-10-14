#include <string>
#include <iostream>
using namespace std;

int main() {
	int visited[26];
	string str;
	cin >> str;
	for (int i = 0; i < 26; i++) visited[i] = -1;
	for (int i = 0; i < str.size(); i++) {
		char cur = str[i];
		if (visited[cur - 'a'] == -1) 
			visited[cur - 'a'] = i;
	}

	for (int i = 0; i < 26; i++) cout << visited[i] << " ";


	return 0;
}