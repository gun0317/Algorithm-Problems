#include <iostream>
#include <vector>
using namespace std;
int ans;
vector <pair <int,int> > v;

int main() {
	int T; cin >> T;
	while (T--) {
		int N, idx, temp; cin >> N >> idx;
		v.clear();	//�� �׽�Ʈ �� ���ο� vector �̿�
		for (int i = 0; i < N; i++) {
			cin >> temp;
			v.push_back(make_pair(0, temp));
		}
		v[idx].first = 1;	//�̿��ڰ� ���ϴ� �ڷ����� ǥ��
		
		ans = 0;
		while (1) {
			//ù��°�� �� ���� �߿䵵���� ���ؼ� �߿䵵�� �� ū ���Ұ�
			//�ϳ��� ������ ù ���Ҹ� ���� �ڷ� ���� + flag����
			//ù���Ұ� �߿䵵 ���� �����Ÿ� flag=0
			int flag = 0;
			for (int i = 1; i < v.size(); i++) {
				if (v[0].second < v[i].second) {
					int tempFirst = v[0].first;	//ù �ڷ��� ���� ����(first)
					int tempSec = v[0].second;	//ù �ڷ��� ���� ����(second)
					v.erase(v.begin());	//ù �ڷḦ ����
					v.push_back(make_pair(tempFirst, tempSec));	//ù �ڷḦ ���� �ڷ� ����
					flag++;
					break;
				}
			}

			//flag�� 0, �� ù ������ �߿䵵�� �� ������.(print �Ǵ� ���)
			if (!flag){
				ans++;
				if (v[0].first == 1)	//��ǥ ����->�ݺ��� break
					break;
				else 
					v.erase(v.begin());
			}
		}

		cout << ans << endl;
	}

	return 0;
}