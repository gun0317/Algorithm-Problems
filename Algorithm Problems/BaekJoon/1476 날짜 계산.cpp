//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int E, S, M;
//	cin >> E >> S >> M;
//	int year=1;
//	int ee=1, ss=1, mm=1;
//	while (1)
//	{
//		
//		ee = year % 15;
//		ss = year % 28;
//		mm = year % 19;
//
//		if (ee == 0)ee = 15;
//		if (ss == 0)ss = 28;
//		if (mm == 0)mm = 19;
//		if (ee == E && ss == S && mm == M)
//			break;
//		year++;
//	}
//	cout << year;
//	return 0;
//}