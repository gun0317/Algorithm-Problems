#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main() {
	int flag1 = 1, flag2 = 0;
	int cnt = 0;
	for (int i = 0; i < 64; i++) {
		char input; scanf(" %c", &input);
		if (flag1%2 && input == 'F') cnt++;
		flag1++; flag2++;
		if (flag2 == 8) {
			flag1++;
			flag2 = 0;
		}
	}

	cout << cnt << endl;
	return 0;
}