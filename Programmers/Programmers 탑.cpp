#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	vector <pair <int, int>> tower;
	stack <pair <int, int>> h;
	int size = heights.size();
	int *ansArr = new int[size];

	for (int i = 0; i < size; i++) ansArr[i] = 0;
	for (int i = size; i > 0; i--) tower.push_back({ i, heights[i - 1] });
	for (int i = 0; i < size; i++) {
		// When the stack is empty
		if (h.empty())
			h.push(tower[i]);
		// When the saved height is higher
		else {
			if (!h.empty() && h.top().second > tower[i].second) {
				h.push(tower[i]);
			}
			// When the current height is higher than former one
			else {
				while (!h.empty() && h.top().second < tower[i].second) {
					ansArr[h.top().first - 1] = tower[i].first;
					h.pop();
				}
				h.push(tower[i]);
			}
		}
	}

	for (int i = 0; i < size; i++) answer.push_back(ansArr[i]);

	return answer;
}

int main() {
	vector <int> h;
	h.push_back(6);
	h.push_back(9);
	h.push_back(5);
	h.push_back(7);
	h.push_back(4);
	//h.push_back(1);
	//h.push_back(5);
	//h.push_back(3);
	//h.push_back(6);
	//h.push_back(7);
	//h.push_back(6);
	//h.push_back(5);
	vector <int> res = solution(h);

	for (int i = 0; i < h.size(); i++) printf("%d ", res[i]);
	

	return 0;
}