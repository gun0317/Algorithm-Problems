//#include <iostream>
//using namespace std;
//int fixedSeats[50], spaces[50];
//int factorTable[50] = { 0,1,1 };
//
//unsigned int factor(int n) {
//	if (n == 0)
//		return 1;
//	if (!factorTable[n]) {
//		factorTable[n] = factor(n-1) + factor(n-2);
//	}
//	return factorTable[n];
//}
//int main()
//{
//	int N, M;
//	cin >> N >> M; int input;
//	for (int i = 1; i <= M; i++) {
//		cin >> input;
//		fixedSeats[i] = input;
//	}
//	//for (int i = 1; i <= M+1; i++) fixedSeats[i]--;
//	for (int i = 1; i <= M; i++) {
//		spaces[i] = fixedSeats[i] - fixedSeats[i - 1]-1;
//	}
//	spaces[M + 1] = N - fixedSeats[M];
//
//	unsigned int ans=1;
//	for (int i = 1; i <= M+1; i++) {
//		ans *= factor(spaces[i]+1);
//	}
//	
//	cout << ans;
//
//
//	return 0;
//}