//#include <iostream>
//#include <algorithm>
//#include <string>
//#define aioue (arr[i]=='a'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'||arr[i]=='e')
//using namespace std;
//int L, C, cnt;
//char arr[20];
//int visited[20];
//
//
//void back(int depth,int cur, int ja, int mo,char* pwd) {
//	if (depth == L && ja > 1 && mo > 0){
//		for (int i = 0; i < L; i++)
//			cout << pwd[i];
//		cout << endl;
//		return;
//	} 
//
//	for (int i = cur+1; i <= C; i++) {
//		if (!visited[i])
//		{
//			visited[i]++;
//			pwd[depth] = arr[i];
//			back(depth + 1, i, aioue?ja:ja+1, aioue?mo+1:mo, pwd);
//			visited[i] = 0;
//		}
//	}
//}
//
//int main()
//{
//	cin >> L >> C;
//	for (int i = 1; i <= C; i++)	cin >> arr[i];
//	sort(arr + 1, arr + 1 + C);
//	char pwd[16] = { '\0', };
//	back(0, 0, 0, 0, pwd);
//	if (cnt == 0)
//		return 0;
//	cout << cnt;
//
//
//	return 0;
//}