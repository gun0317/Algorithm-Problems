#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int size = str.length();

	for (int i = 0; i < size / 2; i++) 
		if (str[i] != str[size - 1 - i]) {
			cout << 0 << endl;
			return 0;
		}
	
	cout << 1 << endl;
	return 0;
}