#include <iostream>
#include <cstdio>
using namespace std;


int main() {
	int a[3], b[3];
	for (int i = 0; i < 3; i++)
		scanf("%1d", &a[i]);
	for (int i = 0; i < 3; i++)
		scanf("%1d", &b[i]);

	int A = a[2] * 100 + a[1] * 10 + a[0];
	int B = b[2] * 100 + b[1] * 10 + b[0];

	int ans = A > B ? A : B;
	cout << ans << endl;



	return 0;
}