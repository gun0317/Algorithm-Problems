#include <iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	for (int lines = 1; lines <= N; lines++) {
		for (int i = 0; i < lines; i++) printf("*");
		for (int i = (N - lines)*2; i > 0; i--) printf(" ");
		for (int i = 0; i < lines; i++) printf("*");
		printf("\n");
	}

	for (int lines = N-1; lines > 0; lines--) {
		for (int i = 0; i < lines; i++) printf("*");
		for (int i = (N - lines) * 2; i > 0; i--) printf(" ");
		for (int i = 0; i < lines; i++) printf("*");
		printf("\n");
	}

	return 0;
}