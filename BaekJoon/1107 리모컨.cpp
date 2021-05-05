#include <iostream>
#include <string>
#include <math.h>
#define pair pair <int, int> 
using namespace std;

int targetChannel, M;
int remote[10] = { 0, };	//���峭 ��ư�� -1�� ǥ�� �������� 0

int main() {
	cin >> targetChannel >> M;
	int temp, ans = abs(targetChannel - 100);
	int crit = ans;			//crit�� ���ڸ� ���� �� ã�� �� ���� 100���� +,-�� ã�°� �� ���� �� �� ����
	//input for unable buttons
	for (int i = 0; i < M; i++) {
		cin >> temp;
		remote[temp] = -1;
	}
	int idx = 0;
	int targetUp = targetChannel;
	int targetDown = targetChannel;

	//using Brute Force : ��ǥ ���ڿ��� +- 1�� �غ��鼭 �������� ���� ������ �������� check
	
	int upFlag = 0, downFlag = 0;	//���γ� �Ʒ��γ� �ִ� ���� ã�Ҵ��� ���� ���


	while (idx < crit) {
		string up = to_string(targetUp);
		string down = to_string(targetDown);
		int flag = 0;	//flag�� ���� ������ ä���� ���ڸ� ������ ������ ä������ ���θ� ��Ÿ��

		if (upFlag == 0)	//target ä�κ��� ������ ������ ���� ����� ���� �� ã�� ��츸
		{
			//target ä�κ��� ������ ������ ��
			for (int i = 0; i < up.size(); i++) {
				if (flag == 0)
					for (int j = 0; j < 10; j++) {
						if (remote[up[i] - 48] == -1)
						{
							flag++;
							break;
						}
					}
				else
					break;
			}
			//������ ������ ���(flag�� ���� ������ ä���� ���ڸ� ������ ������ ä������ ���θ� ��Ÿ��)
			if (flag == 0) {
				if (ans > up.size() + targetUp - targetChannel)
					ans = up.size() + targetUp - targetChannel;
				upFlag++;
			}
			targetUp++;
		}
		//target ä�κ��� �Ʒ����� �ö�� ��
		flag = 0;
		for (int i = 0; i < down.size(); i++) {
			if (flag == 0)
				for (int j = 0; j < 10; j++) {
					if (remote[down[i] - 48] == -1)
					{
						flag++;
						break;
					}
				}
			else
				break;
		}
		//������ ������ ���
		if (flag == 0) {
			if (ans > down.size() + targetChannel - targetDown)
				ans = down.size() + targetChannel - targetDown;
			downFlag++;
		}
		if (targetDown > 0) targetDown--;
		if (upFlag || downFlag) break;	//���ε� �Ʒ��ε� ���� ã�� ��� break
		idx++;	//�� Ȥ�� �Ʒ��� ������ Ƚ�� ���(crit�� �񱳸� ����)
	}

	cout << ans;

	return 0;
}