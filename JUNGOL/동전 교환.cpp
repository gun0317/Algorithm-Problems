#include <iostream>
#include <string.h>
#define MAX 10000
using namespace std;


int coin[20];
int dpTable[65000] = { MAX};

int main()
{
	int i, j, k, n, w;
	//입력
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> coin[i];
	cin >> w;
	//입력

	//dpTable초기화: dpTable[0] = 1, 단위코인은 1로, 나머지는 MAX로.
	for (i = 0; i < w+1; i++)
		dpTable[i] = MAX;
	dpTable[0] = 1;
	for (i = 0; i < n; i++)
		dpTable[coin[i]] = 1;
	//dpTable초기화

	


	//점화식: dpTable[i] = min(dpTable[w-coin[j]]+1), j=0부터 n.
	//dpTable완성하기: 처음엔 재귀함수생각했으나 그냥 반복문으로 모든 index에서 완성시키면 됨
	for (i = 1; i < w+1; i++) 
	{
		for (j = 0; j < n; j++) {
			if(i - coin[j]>0)
				if (dpTable[i] > dpTable[i - coin[j]] + 1)		//단위코인을 바꿨을 때 그 값이 더 작은 경우만
					dpTable[i] = dpTable[i - coin[j]] + 1;			//새로운 단위코인으로 업데이트
			
		}
	}
	//dpTable채워넣기


	
	
	if (dpTable[w] == MAX)				//불가능한 케이스 처리
		cout << "impossible" << endl;
	else
		cout << dpTable[w] << endl;



	return 0;

}