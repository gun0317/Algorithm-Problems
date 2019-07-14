#include <iostream>
#include <string.h>
#define MAX 10000
using namespace std;


int coin[20];
int dpTable[65000] = { MAX};

int main()
{
	int i, j, k, n, w;
	//�Է�
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> coin[i];
	cin >> w;
	//�Է�

	//dpTable�ʱ�ȭ: dpTable[0] = 1, ���������� 1��, �������� MAX��.
	for (i = 0; i < w+1; i++)
		dpTable[i] = MAX;
	dpTable[0] = 1;
	for (i = 0; i < n; i++)
		dpTable[coin[i]] = 1;
	//dpTable�ʱ�ȭ

	


	//��ȭ��: dpTable[i] = min(dpTable[w-coin[j]]+1), j=0���� n.
	//dpTable�ϼ��ϱ�: ó���� ����Լ����������� �׳� �ݺ������� ��� index���� �ϼ���Ű�� ��
	for (i = 1; i < w+1; i++) 
	{
		for (j = 0; j < n; j++) {
			if(i - coin[j]>0)
				if (dpTable[i] > dpTable[i - coin[j]] + 1)		//���������� �ٲ��� �� �� ���� �� ���� ��츸
					dpTable[i] = dpTable[i - coin[j]] + 1;			//���ο� ������������ ������Ʈ
			
		}
	}
	//dpTableä���ֱ�


	
	
	if (dpTable[w] == MAX)				//�Ұ����� ���̽� ó��
		cout << "impossible" << endl;
	else
		cout << dpTable[w] << endl;



	return 0;

}