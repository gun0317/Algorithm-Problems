//#include <iostream>
//#include <stack>
//#include <vector>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//int visited2[1010];
//int visited[1010];
//int N, M, start;
//vector <pair <int, int> > v;
//
//
//void DFS() {
//	stack <int> s;
//	s.push(start);
//	while (!s.empty())
//	{
//		int cur = s.top();
//		s.pop();
//		if (visited[cur])
//			continue;
//		cout << cur << " ";
//		visited[cur] = 1;
//		for (int i = M-1; i >= 0; i--)
//			if (v[i].first == cur && !visited[v[i].second])
//				s.push(v[i].second);
//
//	}
//	cout << endl;
//}
//
//void BFS() {
//	queue <int> q;
//	q.push(start);
//	while (!q.empty())
//	{
//		int cur = q.front();
//		q.pop();
//		if (visited2[cur])
//			continue;
//		cout << cur << " ";
//		visited2[cur] = 1;
//		for (int i = 0; i < M; i++) {
//			if (v[i].first == cur && !visited2[v[i].second])
//				q.push(v[i].second);
//			else if (v[i].second == cur && !visited2[v[i].first])
//				q.push(v[i].first);
//		}
//	}
//	cout << endl;
//
//}
//int main() {
//	//freopen("1.txt", "r", stdin); 
//	cin >> N >> M >> start;
//	
//	//v.resize(M);
//	for (int i = 0; i < M; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		v.push_back(make_pair(x, y));
//	}
//	sort(v.begin(), v.end());
//
//	DFS();
//	BFS();
//	
//	return 0;
//}
//
