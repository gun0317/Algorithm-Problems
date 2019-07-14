#include <iostream>
#include <math.h>
using namespace std;

typedef struct _planet {
	double x, y, radius;
}planets;

double distance(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

int in_outs(double x1, double y1, double x2, double y2, planets p) {
	double d1 = distance(x1, y1, p.x, p.y);
	double d2 = distance(x2, y2, p.x, p.y);
	if ((d1 > p.radius && d2 < p.radius) || (d1<p.radius && d2>p.radius))
		return 1;
	
	return 0;
}

int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		double x1, x2, y1, y2;
		int n, ans = 0;
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		scanf(" %d", &n);
		planets p;
		for (int i = 0; i < n; i++) {
			scanf(" %lf %lf %lf", &p.x, &p.y, &p.radius);
			ans += in_outs(x1, y1, x2, y2, p);
		}
		printf("%d\n", ans);
	}

	return 0;
}