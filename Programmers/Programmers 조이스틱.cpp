#include <string>
using namespace std;
int done, noneA, answer, len, distR, distL;
int visited[30];

int bfs(int curIdx) {
	int toReturn = 0;
	visited[curIdx] = 0;
	// go right
	int idxRight = 0;
	for (int i = 1; i < len; i++)
		if (visited[(curIdx + i) % len] == -1) {
			distR = i;
			idxRight = curIdx + distR;
			break;
		}
	// go left
	int idxLeft = 0;
	for (int i = -1; i > -len; i--) {
		int idx = curIdx + i;
		if (idx < 0)
			idx += len;
		if (visited[idx] == -1) {
			distL = -i;
			idxLeft = idx;
			break;
		}
	}
	if (distR > distL) return idxLeft;
	else return idxRight;
}

int solution(string name) {
	len = name.size();
	for (int i = 0; i < len; i++)
		if (name[i] != 'A') {
			noneA++;
			visited[i] = -1;
		}
	if (name[0] == 'A') noneA++;
	int nextIdx = 0;
	for (int i = 0; i < noneA; i++) {
		int toMove = 0;
		if (name[nextIdx] - 'A' < 'Z' + 1 - name[nextIdx])
			toMove = name[nextIdx] - 'A';
		else toMove = 'Z' + 1 - name[nextIdx];
		answer += toMove;
		answer += distR > distL ? distL : distR;
		nextIdx = bfs(nextIdx);
	}

	return answer;
}

int main() {
	string n = "AZAAAZ";
	printf("%d\n",solution(n));

	return 0;
}