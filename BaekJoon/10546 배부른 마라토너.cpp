#include <iostream>
#include <map>
#include <string>
using namespace std;
map <string, int> names;
string str;

int main() {
	int N; cin >> N;
	//������ �̸��� �Է¹ް� map�� ����. key�� �̸�, value�� 1��
	for (int i = 0; i < N; i++) {
		cin >> str;
		names[str]++;
	}

	//������ �̸��� �̸��� �Է� �����鼭 erase. �̿����ڸ� ����.
	for (int i = 0; i < N - 1; i++) {
		cin >> str;
		//counted�� ���������� ���� ����
		int counted = names[str];
		names.erase(str);	//�ش� �̸��� ����������
		for (int j = 0; j < counted-1; j++) {	//�������� �� -1 ��ŭ �ٽ� names�� ����
			names[str]++;
		}
	}
	
	cout << names.begin()->first << endl;


	return 0;
}