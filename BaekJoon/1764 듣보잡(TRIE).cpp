#define _CRT_SECURE_NO_WARNINGS
#define MAX_BUCKET 1000007
#include <iostream>
using namespace std;

typedef struct NODE {
	char alphabet;
	bool isWord;
	NODE* childAlpha[30];
}NODE;

NODE static_allocated_nodes[500010];
int static_alloc_idx = 0;
NODE* static_alloc() {
	return &static_allocated_nodes[static_alloc_idx++];
}

//trie
typedef struct TRIE {
	NODE* root;

	void init() {
		root = static_alloc();
		root->alphabet = 0;
		root->isWord = false;
		for (int i = 0; i < 30; i++)
			root->childAlpha[i] = 0;
	}

	void push(const char* str) {
		NODE* cur = root;
		for (int i = 0; str[i]; i++) {
			int curIdx = str[i] - 'a';
			if (cur->childAlpha[curIdx])
				cur = cur->childAlpha[curIdx];
			else {
				NODE* temp = static_alloc();
				temp->alphabet = curIdx + 'a';
				temp->isWord = false;
				cur->childAlpha[curIdx] = temp;
				cur = cur->childAlpha[curIdx];
			}
		}
		cur->isWord = true;
	}

	int find(const char* str) {
		NODE* cur = root;
		for (int i = 0; str[i]; i++) {
			int curIdx = str[i] - 'a';
			if (cur->childAlpha[curIdx]) {
				cur = cur->childAlpha[curIdx];
			}
			else return 0;
		}
		if (cur->isWord) return 1;
		else return 0;
	}

	void printList(NODE* cur, char* str, int strIdx) {
		NODE* temp = cur;
		if (temp->isWord)
			printf("%s\n", str);
		for (int i = 0; i < 27; i++) {
			if (temp->childAlpha[i]) {
				str[strIdx] = i + 'a';
				str[strIdx + 1] = '\0';
				printList(cur->childAlpha[i], str, strIdx + 1);
			}
		}
	}
}TRIE;

TRIE heard, both;

int main() {
	int N, M;
	int ans = 0;
	heard.init();
	both.init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		char temp[20];
		scanf(" %s", temp);
		heard.push(temp);
	}

	for (int i = 0; i < M; i++) {
		char temp[20];
		scanf(" %s", temp);
		if (heard.find(temp)) {
			ans++;
			both.push(temp);
		}
	}
	char bucketStr[30];
	cout << ans << endl;
	both.printList(both.root, bucketStr, 0);


	return 0;
}