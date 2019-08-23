#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int lines = 0; lines < N; lines++) {
		for (int blank = N - lines - 1; blank > 0; blank--) printf(" ");
		for (int stars = 0; stars < lines * 2 + 1; stars++) printf("*");
		printf("\n");
	}

	return 0;
}