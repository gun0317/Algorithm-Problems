#include <iostream>
#include <vector>
using namespace std;
typedef struct dCurve_{
	int row, col, dir, gen;	//row = y, col = x
	vector <int> prevPath;
}dCurve;
int dr[] = { 0,-1,0,1 }, dc[] = { 1,0,-1,0 };
int N, ans, visited[110][110];
vector <dCurve> dCurves;

void check();

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		dCurve temp; int x, y, d, g;
		cin >> x >> y >> d >> g;
		temp.row = y; temp.col = x; temp.dir = d; temp.gen = g;
		dCurves.push_back(temp);
	}
	check();
	cout << ans;

	return 0;
}

void check() {
	for (int i = 0; i < N; i++) {
		// determining the final path
		dCurve cur = dCurves[i];
		cur.prevPath.push_back(cur.dir);
		for (int j = 0; j < cur.gen;j++) {
			int cursize = cur.prevPath.size();
			for (int k = cursize - 1; k >= 0; k--) 
				cur.prevPath.push_back((cur.prevPath[k] + 1) % 4);
		}

		// marking on the visited
		for (int i = 0; i < cur.prevPath.size(); i++) {
			visited[cur.row][cur.col] = 1;
			cur.row += dr[cur.prevPath[i]];
			cur.col += dc[cur.prevPath[i]];
		}
		visited[cur.row][cur.col] = 1;
	}
	
	// checking the squares in the visited.
	for (int r = 0; r < 100; r++)
		for (int c = 0; c < 100; c++) 
			if (visited[r][c] && visited[r][c + 1] && visited[r + 1][c] && visited[r + 1][c + 1])
				ans++;
		
}