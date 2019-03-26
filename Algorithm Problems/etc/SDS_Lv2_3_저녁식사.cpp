//#include <iostream>
//#include <vector>
//#include <functional>
//#include <algorithm>
//#define MAX_NUM 1000000000
//using namespace std;
//
//int main() {
//	double T, N, x, y;
//	cin >> T;
//	int test = 1;
//	while (T--) {
//		cin >> N;
//		double xMax = MAX_NUM, yMax = MAX_NUM;
//		vector <pair <double, double>> xFirst;
//		vector <pair <double, double>> yFirst;
//		vector <pair <double, double>> copy;
//		vector <pair <double, double>> candidates;
//		for (int i = 0; i < N; i++) {
//			cin >> x >> y;
//			xFirst.push_back(make_pair(x, y));
//			copy.push_back(make_pair(x, y));
//			yFirst.push_back(make_pair(y, x));
//		}
//		sort(xFirst.begin(), xFirst.end(), greater <pair <double, double>>());
//		sort(yFirst.begin(), yFirst.end(), greater <pair <double, double>>());
//		
//		int xflag = 0, yflag =0;
//		while (xFirst.back().second < yMax) 
//		{
//			yMax = xFirst.back().second;
//			x = xFirst.back().first;
//			y = xFirst.back().second;
//			candidates.push_back(xFirst.back());
//			while (xFirst.back().first == x)
//			{
//				if (xFirst.size() == 1) {
//					xflag++;
//					break;
//				}
//				xFirst.pop_back();
//			}
//			if (xflag > 0) break;
//		}
//
//		while (yFirst.back().second < xMax)
//		{
//			xMax = yFirst.back().second;
//			y = yFirst.back().first;
//			x = yFirst.back().second;
//			candidates.push_back(make_pair(x, y));
//			while (yFirst.back().first == y)
//			{
//				if (yFirst.size() == 1) {
//					yflag++;
//					break;
//				}
//				yFirst.pop_back();
//			}
//			if (yflag > 0) break;
//		}
//
//		sort(candidates.begin(), candidates.end());
//		candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
//		sort(candidates.begin(), candidates.end());
//		
//		vector <double> ans;
//		for (int i = 0; i < candidates.size(); i++) {
//			int j = 0;
//			while (candidates[i] != copy[j]) {
//				j++;
//			}
//			ans.push_back(j+1);
//		}
//
//		printf("#%d ", test);
//		test++;
//		for (int i = 0; i < ans.size(); i++) printf("%0.f ", ans[i]);
//		cout << candidates.max_size();
//		printf("\n");
//	}
//	
//	return 0;
//}
///*
//3           
//4            
//1 5
//2 4
//3 5
//4 7
//8            
//7 3
//12 1
//2 9
//11 7
//7 2
//4 3
//9 4
//5 5
//10           
//45 62
//60 60
//21 22
//55 56
//41 9
//70 37
//68 74
//58 42
//32 68
//22 35
//
//*/