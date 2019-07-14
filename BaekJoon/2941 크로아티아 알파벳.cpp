//#include <iostream>
//#include <string>
//using namespace std;
//
//
//int main() {
//	string str;
//	getline(cin, str);
//	int size = str.size();
//	int ans = size;
//	for (int i = 0; i < size; i++) {
//		if (str[i] == '-') {
//			ans--;
//		}
//		if (str[i] == '=' && str[i - 1] == 'z' && i - 2 >= 0 && str[i - 2] == 'd') {
//			ans--;
//		}
//		if (str[i] == '=' && !(i - 2 >= 0 && str[i - 1] == 'z' &&str[i - 2] == 'd')) {
//			ans--;
//		}
//		if (str[i] == 'j' &&i - 1 >= 0 && (str[i - 1] == 'l' || str[i - 1] == 'n')) {
//			ans--;
//		}
//	}
//	cout << ans << endl;
//
//	return 0;
//}