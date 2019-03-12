//#include <iostream>
//#include <string>
//#include <math.h>
//#define pair pair <int, int> 
//using namespace std;
//
//int targetChannel, M;
//int remote[10] = { 0, };	//고장난 버튼은 -1로 표기 나머지는 0
//
//int main() {
//	cin >> targetChannel >> M;
//	int temp, ans = abs(targetChannel - 100);
//	int crit = ans;			//crit은 숫자를 누른 후 찾는 것 보다 100에서 +,-로 찾는게 더 빠를 때 그 기준
//	//input for unable buttons
//	for (int i = 0; i < M; i++) {
//		cin >> temp;
//		remote[temp] = -1;
//	}
//	int idx = 0;
//	int targetUp = targetChannel;
//	int targetDown = targetChannel;
//
//	//using Brute Force : 목표 숫자에서 +- 1씩 해보면서 리모컨을 눌러 가능한 조합인지 check
//	
//	int upFlag = 0, downFlag = 0;	//위로나 아래로나 최단 값을 찾았는지 여부 기록
//
//
//	while (idx < crit) {
//		string up = to_string(targetUp);
//		string down = to_string(targetDown);
//		int flag = 0;	//flag는 현재 리모컨 채널이 숫자를 눌러서 가능한 채널인지 여부를 나타냄
//
//		if (upFlag == 0)	//target 채널보다 위에서 내려올 때의 결과를 아직 못 찾은 경우만
//		{
//			//target 채널보다 위에서 내려올 때
//			for (int i = 0; i < up.size(); i++) {
//				if (flag == 0)
//					for (int j = 0; j < 10; j++) {
//						if (remote[up[i] - 48] == -1)
//						{
//							flag++;
//							break;
//						}
//					}
//				else
//					break;
//			}
//			//가능한 조합인 경우(flag는 현재 리모컨 채널이 숫자를 눌러서 가능한 채널인지 여부를 나타냄)
//			if (flag == 0) {
//				if (ans > up.size() + targetUp - targetChannel)
//					ans = up.size() + targetUp - targetChannel;
//				upFlag++;
//			}
//			targetUp++;
//		}
//		//target 채널보다 아래에서 올라올 때
//		flag = 0;
//		for (int i = 0; i < down.size(); i++) {
//			if (flag == 0)
//				for (int j = 0; j < 10; j++) {
//					if (remote[down[i] - 48] == -1)
//					{
//						flag++;
//						break;
//					}
//				}
//			else
//				break;
//		}
//		//가능한 조합인 경우
//		if (flag == 0) {
//			if (ans > down.size() + targetChannel - targetDown)
//				ans = down.size() + targetChannel - targetDown;
//			downFlag++;
//		}
//		if (targetDown > 0) targetDown--;
//		if (upFlag || downFlag) break;	//위로든 아래로든 답을 찾은 경우 break
//		idx++;	//위 혹은 아래로 움직인 횟수 기록(crit과 비교를 위해)
//	}
//
//	cout << ans;
//
//	return 0;
//}