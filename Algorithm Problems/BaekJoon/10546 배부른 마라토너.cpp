//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//map <string, int> names;
//string str;
//
//int main() {
//	int N; cin >> N;
//	//참가자 이름을 입력받고 map에 저장. key는 이름, value는 1로
//	for (int i = 0; i < N; i++) {
//		cin >> str;
//		names[str]++;
//	}
//
//	//완주자 이름을 이름을 입력 받으면서 erase. 미완주자만 남게.
//	for (int i = 0; i < N - 1; i++) {
//		cin >> str;
//		//counted에 동명이인의 수를 저장
//		int counted = names[str];
//		names.erase(str);	//해당 이름을 싹지웠으니
//		for (int j = 0; j < counted-1; j++) {	//동명이인 수 -1 만큼 다시 names에 저장
//			names[str]++;
//		}
//	}
//	
//	cout << names.begin()->first << endl;
//
//
//	return 0;
//}