#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		char current_time[10], promised_time[10];
		scanf("%s", current_time);
		scanf("%s", promised_time);
		int curHour = (current_time[0] - '0') * 10 + current_time[1];
		int curMin = (current_time[3] - '0') * 10 + current_time[4];
		int curSec = (current_time[6] - '0') * 10 + current_time[7];

		int proHour = (promised_time[0] - '0') * 10 + promised_time[1];
		int proMin = (promised_time[3] - '0') * 10 + promised_time[4];
		int proSec = (promised_time[6] - '0') * 10 + promised_time[7];
		
		int sec = proSec - curSec;
		int min = proMin - curMin;
		int hour = proHour - curHour;
		if (sec < 0) {
			sec += 60;
			min -= 1;
		}
		if (min < 0) {
			min += 60;
			hour -= 1;
		}
		if (hour < 0) {
			hour += 24;
		}
		char ansHour[2],ansMin[2],ansSec[2];
		ansHour[0] = hour / 10 + '0';
		ansHour[1] = hour % 10 + '0';
		ansMin[0] = min / 10 + '0';
		ansMin[1] = '0' + min % 10;
		ansSec[0] = sec / 10 + '0';
		ansSec[1] = sec % 10 + '0';
	
		printf("#%d %c%c:%c%c:%c%c\n", test_case, ansHour[0], ansHour[1], ansMin[0], ansMin[1], ansSec[0], ansSec[1]);



	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}