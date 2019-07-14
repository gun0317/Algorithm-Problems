//#include <iostream>
//// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
//#include <sstream>
//#include <string>
//#include <cmath>
//using namespace std;
//
//int main() {
//	string line;
//	getline(cin, line);
//	stringstream ss(line);
//	int cur = 20000;//ภÜพื
//	for (int distance; !(ss >> distance).fail(); ) {
//		// @todo Write your code here.
//		int temp = cur;
//		if (distance < 4 || distance > 178) break;
//		double over = distance - 40;
//		if (over <= 0) cur -= 720;
//		else cur -= 720 + 80 * ceil(over / 8);
//		if (cur < 0) {
//			cur = temp;
//			break;
//		}
//		
//	}
//	// @todo Write your code here.
//	cout << cur << endl;
//	return 0;
//}
