#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int lines = N-1; lines >= 0; lines--) {
		for (int blank = 1; blank < N-lines; blank++) printf(" ");
		for (int stars = 0; stars <= 2 * lines; stars++) printf("*");
		printf("\n");
	}

	for (int lines = 1; lines <= N-1; lines++) {
		for (int blank = 1; blank < N - lines; blank++) printf(" ");
		for (int stars = 0; stars <= 2 * lines; stars++) printf("*");
		printf("\n");
	}

	return 0;
}