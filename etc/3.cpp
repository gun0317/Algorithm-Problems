//#include <iostream>
//#include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
//#include <sstream>
//#include <map>
//#include <algorithm>
//#include <string>
//#include <vector>
//using namespace std;
//vector <map <int, int> > note;
//vector <int> lines[10000];
//vector <int> candidate;
//
//int main() {
//	int n, N;
//	cin >> n;
//	N = n;
//	int idx = 0;  // drop a newline traling n
//	while (1+n-- > 0) {
//		string line;
//		getline(cin, line);
//		stringstream ss(line);
//		int fork;
//		for (fork; !(ss >> fork).fail(); ) {  // read forks from a note
//			lines[idx].push_back(fork);		  // @todo Write your code here.
//		}
//		lines[idx].pop_back();
//		idx++;
//		candidate.push_back(fork);		//마지막 나온 도착지: 하구 후보
//	}
//	//중복제거
//	candidate.erase(candidate.begin());
//	sort(candidate.begin(), candidate.end());
//	candidate.erase(unique(candidate.begin(), candidate.end()),candidate.end());
//	
//	//candidate 중 어떤 line 중 중간에 위치할 경우 제외
//	int candiSize = candidate.size();
//	for (int j = 0; j < candiSize; j++) {
//		for (int i = 0; i < N; i++) {
//			find(lines[i].begin(), lines[i].end() - 1, candidate[j]);
//
//			}
//			
//		}
//	}
//
//	
//
//	// @todo Write your code here.
//	return 0;
//}
//
////8
////3 8 11 12
////2 7 11
////1 6 7
////10 12
////3 8
////4 8 11
////5 9 11 12
////3 8 11
////
////12
//
////8
////1 2 4 7
////3 4 7 9
////5 8 9
////6 8
////10 12 14
////11 12 14 17
////15 17
////13 16 17
////
////9 17