// trie implementation
// 20190724
#define NUM_ALPHABET 30
#define MAX_LENGTH 50
#define MAX_NODE 1000
#define MAX_BUCKET 100
#include <iostream>
using namespace std;

typedef struct trieNode {
	// its index is its alphabet
	char alphabet;
	bool isWord;
	trieNode* child[NUM_ALPHABET];
	trieNode() {
		for (int i = 0; i < NUM_ALPHABET; i++) child[i] = 0;
		isWord = false;
		alphabet = 0;
	}
}trieNode;
trieNode trieNodes[MAX_NODE];
int trie_alloc_idx = 0;
trieNode* trie_alloc() {
	return &trieNodes[trie_alloc_idx++];
}

void _strcpy(char* dest, const char* src) {
	while (*src != '\0') *dest++ = *src++;
	*dest = '\0';
}


struct TRIE {
	int wordNum = 0;

	// Overall procedure of push: 
	// check the child nodes and if empty, add for each character of input str.
	// At the end of the word, mark isWord.
	void push(trieNode* root, char* str) {
		trieNode* cur = root;
		for (int i = 0; str[i]; i++) {
			int nextIdx = str[i] - 'a';
			// When the prefix already exists
			if (cur->child[nextIdx]) cur = cur->child[nextIdx];
			// When its not
			else {
				trieNode* temp = trie_alloc();
				cur->child[nextIdx] = temp;
				temp->alphabet = nextIdx + 'a';
				cur = cur->child[nextIdx];
			}
		}
		cur->isWord = true;
		wordNum++;
	}

	// find
	// follow the child nodes until the end of input character.
	// check if the end of input character's isWord is true.
	trieNode* find(trieNode* root, const char* str) {
		trieNode* cur = root;
		for (int i = 0; str[i]; i++) {
			int nextIdx = str[i] - 'a';
			if (cur->child[nextIdx]) {
				cur = cur->child[nextIdx];
			}
			//if there's nothin
			else return 0;
		}
		if (cur->isWord) return cur;
		else return 0;
	}

	// find the node and make its isWord false.
	void deleteStr(trieNode* root, const char* str) {
		trieNode* temp = find(root, str);
		temp->isWord = false;
	}

	// save all the words in the trie into 2D char array RECURSIVELY.
	// str: current word. strIdx: cursor for current word. res: 2D char array to save the results. resIdx: num of results
	// DFS!
	void saveList(trieNode* root, char* str, int strIdx, char res[][MAX_LENGTH], int &resIdx) {
		// DFS end condition
		if (root->isWord)
			_strcpy(res[resIdx++], str);
		// DFS traverse(for all the alphabet)
		for (int i = 0; i < NUM_ALPHABET; i++) {
			if (root->child[i]) {
				str[strIdx] = i + 'a';
				str[strIdx + 1] = '\0';
				saveList(root->child[i], str, strIdx + 1, res, resIdx);
			}
		}
	}
};

int main() {
	trieNode* root = trie_alloc();
	TRIE t;
	char arr[4][10] = { "abc","abcsd","xyz","avz" };

	//Pushing
	for (int i = 0; i < 4; i++)
		t.push(root,arr[i]);
	//Deleting
	t.deleteStr(root, "avz");
	char str[1000], res[10][MAX_LENGTH];
	int resIdx = 0;

	//Saving as a char[][] list
	t.saveList(root, str, 0, res, resIdx);
	for (int i = 0; i < resIdx; i++) 
		printf("%s\n", res[i]);

	// Finding
	if (t.find(root, "abc") != 0) cout << "found";
	else cout << "not found";
	cout << endl;
	if (t.find(root, "ab") != 0) cout << "found";
	else cout << "not found";
	cout << endl;

	return 0;
}