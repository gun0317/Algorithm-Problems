#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX_SIZE 200007
using namespace std;

typedef struct node_ {
	unsigned long key;
	node_* next_node;
}node;
node _node[100010];

int static_allocation_idx = 0;

node* static_alloc() {
	return &_node[static_allocation_idx++];
}

struct hashTable {
	// A array of pointer to the node; just pointers.
	node* bucket[MAX_SIZE];

	// Initializes each node of the hash table. empty -> key, value = -1.
	// Can the empty be noted as -1?????????
	void init() {
		for (int i = 0; i < MAX_SIZE; i++) {
			bucket[i] = 0;
		}
	}

	int find(unsigned long _key) {
		int h = hash_function(_key);
		// When the bucket for input key is empty => failed to find the target
		if (bucket[h] == 0) {
			return 0;
		}

		for (node* itr = bucket[h]; itr != 0; itr = itr->next_node) {
			if (itr->key == _key)
				return 1;
		}

		return 0;
	}

	void add(unsigned long _key) {
		int h = hash_function(_key);
		node* temp = static_alloc();
		temp->key = _key; temp->next_node = 0;

		// When the bucket for input key is empty
		if (bucket[h] == 0) {
			bucket[h] = temp;
		}
		// When the bucket for input key is not empty -> make temp the first node
		else {
			node* was_first = bucket[h];
			temp->next_node = was_first;
			bucket[h] = temp;
		}
	}

	unsigned long hash_function(unsigned long key) {
		unsigned long h = 5381;
		h = (h + key) % MAX_SIZE;

		return h;
	}
} hT;

int main() {
	int N, M;
	unsigned long _key;
	static_allocation_idx = 0;
	hT.init();
	scanf("%d", &N);
	while (N--) {
		scanf(" %ul", &_key);
		hT.add(_key);
	}

	scanf(" %d", &M);
	while (M--) {
		scanf("%ul", &_key);
		printf("%d\n", hT.find(_key));
	}

	return 0;
}