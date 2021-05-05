#include <iostream>
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

int main() {
	int r, g, b;
	int N;
	cin >> N; cin >> r >> g >> b; --N;
	while (N--)
	{
		int newR, newG, newB;
		cin >> newR >> newG >> newB;

		newR += MIN(g, b);
		newG += MIN(r, b);
		newB += MIN(r, g);

		r = newR;
		g = newG;
		b = newB;
	}

	cout << MIN(r, MIN(g, b));

	return 0;
}