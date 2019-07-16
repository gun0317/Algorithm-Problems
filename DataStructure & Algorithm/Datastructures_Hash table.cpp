#define MAX_INPUT_NODES 1000
#define NUM_BUCKETS 100
#include <iostream>
using namespace std;

////////////////
///Hash Table///
////////////////

typedef struct NODE {
	unsigned long key;
	int data;
	NODE* next_node;
}NODE;

// Static allocation
int static_alloc_idx = 0;
NODE static_allocated_nodes[MAX_INPUT_NODES];
NODE* static_alloc() {
	return &static_allocated_nodes[static_alloc_idx++];
}
//

typedef struct hashTable {
	NODE* bucket[NUM_BUCKETS];

	void init() {
		for (int i = 0; i < NUM_BUCKETS; i++)
			bucket[i] = 0;
	}

	void add(unsigned long _key, int _data) {
		int h = hash(_key);
		NODE* temp = static_alloc();
		temp->key = _key; temp->data = _data;
		temp->next_node = 0;
		// Empty -> add right away
		if (bucket[h] == 0) {
			bucket[h] = temp;
		}
		// Not empty -> add as the first elment of the chain
		else {
			temp->next_node = bucket[h];
			bucket[h] = temp;
		}
	}

	NODE* find(unsigned long _key) {
		int h = hash(_key);
		NODE* temp = static_alloc();
		temp->key = -1; temp->data = -1;
		temp->next_node = 0;
		// empty-> return right away
		// Not empty -> traverse the chain
		if (bucket[h] != 0) {
			NODE* cur = bucket[h];
			while (cur != 0) {
				if (cur->key == _key) {
					temp->key = cur->key; temp->data = cur->data;
					temp->next_node = cur->next_node;
					break;
				}
				cur = cur->next_node;
			}
		}
		return temp;
	}

	int hash(unsigned long _key){
		unsigned long h = 5381;
		h = ((h << 5) + h + _key) % NUM_BUCKETS;
		return (int)h;
	}
};




int main() {
	hashTable hT;
	hT.init();
	hT.add(1, 12345);
	hT.add(5, 123123);
	hT.add(7, 5431231); 
	hT.add(12, 4321);
	hT.add(-121232, -123);

	NODE* found;
	for (int i = 0; i < 13; i++) {
		found = hT.find(i);
		if (found->key != -1) {
			cout << "key for "<<i<< " is "<< found->key << ", it has data of " << found->data << endl;
		}
		else {
			cout << "There's no such data for " << i << endl;
		}
	}
	found = hT.find(-121232);
	if (found->key != -1) {
		cout << "key for -121232 is " << found->key << ", it has data of " << found->data << endl;
	}
	else {
		cout << "There's no such data for " << -121232 << endl;
	}
	

	return 0;
}