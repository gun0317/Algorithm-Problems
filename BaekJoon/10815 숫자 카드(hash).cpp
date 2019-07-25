constexpr auto MAX_BUCKET = 500010*2;
constexpr auto MAX_NODE = 500010;
#include <iostream>
using namespace std;

typedef struct hashNode {
	unsigned long key;
	hashNode* nextNode;
	hashNode():key(0),nextNode(0) {}
}hashNode;
hashNode static_alloc_nodes[MAX_NODE];
int static_alloc_idx = 0;
hashNode* static_alloc() {
	return &static_alloc_nodes[static_alloc_idx++];
}

typedef struct hashTable {
	hashNode* bucket[MAX_BUCKET];

	void init() {
		for (int i = 0; i < MAX_BUCKET; i++) bucket[i] = 0;
	}

	void push(unsigned long _key) {
		int h = hash(_key);
		hashNode* toInsert = static_alloc();
		toInsert->key = _key;
		if (bucket[h] == 0) 
			bucket[h] = toInsert;
		else {
			toInsert->nextNode = bucket[h];
			bucket[h] = toInsert;
		}
	}

	int find(int _key) {
		int h = hash(_key);
		hashNode* cursor = bucket[h];
		if (cursor == 0) return 0;
		while(cursor != 0) {
			if (cursor->key == _key) return 1;
			else
				cursor = cursor->nextNode;
		}
		return 0;
	}

	unsigned long hash(unsigned long _key) {
		unsigned long h = 5381;
		h = ((h >> 5) + h + _key) % MAX_BUCKET;
		return h;
	}
}hashTable;

int N, M;
hashTable have;
int main() {
	have.init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf(" %d", &temp);
		have.push(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		scanf(" %d", &temp);
		printf("%d ", have.find(temp));
	}
	cout << endl;

	return 0;
}