///*1. There is a building of “n” floors. There is an elevator in the building which has “UP” and “DOWN” buttons. 
//By pressing the “UP” button, the elevator moves up exactly “a” floors. 
//By pressing the “DOWN” button, the elevator moves down exactly “b” floors. 
//If you attempt to move the elevator to lower than the first floor or higher than the “n”th floor, the elevator does not move. 
//Now, you are in the “k” floor and want to go to the “m”th floor. 
//Compute and print out the minimum number of times you should press the "UP" or "DOWN" buttons to go to the destination. 
//Assume that 1n9999.
//
//Input)
//  The first line of the input should be the number of test cases.
//  For each test case, a user should provide “n”, “a”, “b”, “k”, and “m” in order.
// 
//Output)
//  Print format should be “test #[testcase_number] : [result] UP, [result] DOWN”.
//  If there is no feasible solution, your program should print “IMPOSSIBLE”.
//*/
//#include <stdio.h>
//
//int n, a, b, k, m;	//n<10000
//void ans();
//
//int main(void) {
//	int testCase, num=1;
//	scanf("%d", &testCase);
//	while (testCase--) {
//		scanf(" %d", &n);
//		scanf(" %d", &a);
//		scanf(" %d", &b);
//		scanf(" %d", &k);
//		scanf(" %d", &m);
//		//dep = u = d = min =0; // 각 케이스 별 depth,up,down 변수 초기화
//		printf("test #%d : ", num++);
//		ans();
//	}
//
//	return 0;
//}
//
//void ans() {
//	int infinityCheck = 0;
//	int up = 0, down = 0, cur = k;
//	while (1) {
//		//반복횟수가 지나치게 많은 경우 check
//		if (infinityCheck++ > 10000) {
//			printf("IMPOSSIBLE\n");
//			return;
//		}
//		if (cur == m) {	//목적지 도달 시
//			printf("%d UP, %d DOWN\n", up, down);
//			return;
//		}
//		//목적지 보다 낮은 층에 있을 때
//		if (cur < m) {
//			//최대 높이 때문에 올라갈 수 없어서 내려갔다가 올라가야할 때
//			if (cur + a > n && cur - b > 0) {	
//				down++;
//				cur -= b;
//			}
//			//올라갈 수 있을 때
//			else if (cur + a < n + 1) {
//				up++;
//				cur += a;
//			}
//		}
//		//목적지 보다 높은 층에 있을 때
//		if (cur > m) {
//			//최저 높이 때문에 내려갈 수 없어서 올라갔다가 내려가야 할 때
//			if (cur - b <= 0 && cur + a < n + 1) {
//				up++;
//				cur += a;
//			}
//			//내려갈 수 있을 때
//			else if (cur - b > 0) {
//				down++;
//				cur -= b;
//			}
//		}
//	}
//
//
//}