//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string.h>
//using namespace std;
//int x, n, l[1000000];
//vector <pair<int, int> > v;
//
//
//void binary(int left, int right, int target) {
//	if (left > right)
//		return;
//	int mid = (left + right) / 2;
//	if (l[mid] < target) binary(mid + 1, right, target);
//	else if (l[mid] > target) binary(left, mid - 1, target);
//	else if(l[mid] == target){
//		v.push_back(make_pair(x - target, target));
//		return;
//	}
//	
//}
//
//int main()
//{
//	while (cin >> x) {
//		cin >> n;
//		x *= 10000000;
//		for (int i = 0; i < n; i++)
//			cin >> l[i];
//		sort(l, l + n);
//
//		for (int i = 0; i < n; i++)
//			binary(i + 1, n - 1, x - l[i]);
//
//		if (v.size() > 0)
//		{
//			sort(v.begin(), v.end());
//			printf("yes %d %d\n", v[0].first, v[0].second);
//		}
//		else
//			cout << "danger" << endl;
//		v.clear();
//		memset(l, 0, sizeof(l));
//	}
//	
//	return 0;
//}