#define MAX_NODE 100100
typedef struct TrieNode {
	bool isWord;
	char ownCharacter;
	int wordsDown;
	TrieNode* parent;
	TrieNode* child[28];
}TrieNode;
TrieNode static_TrieNodes[MAX_NODE];
int static_idx = 0;
TrieNode* static_alloc() {
	static_TrieNodes[static_idx].isWord = false;
	static_TrieNodes[static_idx].ownCharacter = 0;
	static_TrieNodes[static_idx].wordsDown = 0;
	static_TrieNodes[static_idx].parent = 0;
	for (int i = 0; i < 28; i++) static_TrieNodes[static_idx].child[i] = 0;
	return &static_TrieNodes[static_idx++];
}

typedef struct trie {
	TrieNode* root;
	int totalNum = 0;

	void init() {
		static_idx = 0;
		this->root = static_alloc();
		this->totalNum = 0;
	}

	void push(int len, char* _input) {
		char* toShow = _input;
		TrieNode* cur = root;
		while (*_input != '\0') {
			int nextIdx = *_input - 'a';
			if (cur->child[nextIdx] == 0) {
				TrieNode* temp = static_alloc();
				temp->ownCharacter = *_input;
				temp->parent = cur;
				cur->child[nextIdx] = temp;
			}
			cur = cur->child[nextIdx];
			_input++;
		}
		cur->isWord = true;
		// Go reverse updating the wordsDown.
		while (cur != root) {
			cur->wordsDown++;
			cur = cur->parent;
		}
		root->wordsDown++;
		//cout << "the word " << toShow << " inserted." << endl;
	}

	int findWordsDown(int len, char* _input) {
		char* toShow = _input;
		TrieNode* cur = root;
		while (*_input != '\0') {
			int nextIdx = *_input - 'a';
			if (cur->child[nextIdx] == 0) return 0;
			cur = cur->child[nextIdx];
			_input++;
		}
		//cout << "for " << toShow << " we have " << cur->wordsDown << endl;
		return cur->wordsDown;
	}
}trie;

trie t;
void init(void) {
	t.init();
}

void insert(int buffer_size, char *buf) {
	t.push(buffer_size, buf);
}

int query(int buffer_size, char *buf) {
	return t.findWordsDown(buffer_size, buf);
}