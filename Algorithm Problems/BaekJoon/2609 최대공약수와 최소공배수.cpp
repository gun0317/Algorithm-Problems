//#include <cstdio>
//
//int gcd(int a,int b) {
//	return b ? gcd(b, a%b) : a;
//}
//
//int main(int a,int b,int i) {
//	
//	int T; scanf("%d", &T);
//	while (T--) {
//		scanf("%d %d", &a, &b);
//		int gcd_ = gcd(a, b);
//		printf("%d\n", a*b / gcd_);
//	}
//	return 0;
//}