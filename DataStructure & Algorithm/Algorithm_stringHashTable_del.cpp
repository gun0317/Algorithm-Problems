#define MAX_NODES 50
#define MAX_BUCKET 2
#include <iostream>
using namespace std;

struct hashNode {
	char str[20];
	hashNode* nextNode;
	hashNode* prevNode;
	hashNode() {
		nextNode = 0, prevNode = 0;
	}
}static_alloc_nodes[MAX_NODES];

int static_alloc_idx = 0;
hashNode* static_alloc() {
	return &static_alloc_nodes[static_alloc_idx++];
}

void myStrcpy(char* dest, const char* src) {
	for (; *src != '\0'; *dest++ = *src++);
}

int myStrcmp(const char* s1, const char* s2) {
	while (*s2 != '\0') {
		if (*s1 > *s2) return 1;
		else if (*s1 < *s2) return -1;
		s1++, s2++;
	}
	if (*s1 != '\0') return 1;
	else return 0;
}

struct strHashTable {
private:
	hashNode* bucket[MAX_BUCKET];

	int hash(const char* item) {
		unsigned long h = 5381;
		while (*item != '\0')
			h = ((h >> 5) + h + *item++) % MAX_BUCKET;
		return (int)h;
	}
	hashNode* findBucket(const char* item) {
		int h = hash(item);
		if (bucket[h] == 0) return 0;
		else
			return bucket[h];
	}

public:
	void init() {
		for (int i = 0; i < MAX_BUCKET; i++) bucket[i] = 0;
	}

	void push(const char* item) {
		int h = hash(item);
		hashNode* toInsert = static_alloc();
		myStrcpy(toInsert->str, item);
		hashNode* cur = bucket[h];
		if (cur == 0) {
			bucket[h] = toInsert;
			toInsert->prevNode = 0;
			return;
		}
		else {
			bucket[h]->prevNode = toInsert;
			toInsert->nextNode = bucket[h];
			bucket[h] = toInsert;
		}
		cout << item << " added" << endl;
	}

	int find(const char* item) {
		int h = hash(item);
		if (bucket[h] == 0)return 0;
		hashNode* cur = bucket[h];
		while (cur != 0) {
			if (myStrcmp(cur->str, item) == 0) return 1;
			cur = cur->nextNode;
		}
		return 0;
	}

	void del(const char* item) {
		hashNode* cur = findBucket(item);
		if (cur == 0) return;
		while (cur != 0) {
			if (myStrcmp(cur->str, item) == 0) break;
			cur = cur->nextNode;
		}
		if (myStrcmp(cur->str, item) != 0) return;

		hashNode* prev = cur->prevNode;
		hashNode* next = cur->nextNode;
		if (prev != 0) prev->nextNode = next;
		if (next != 0) next->prevNode = prev;
		cout << item << " deleted" << endl;
	}
};

int main() {
	char s1[] = "abc", s2[] = "abcd", s3[] = "123", s4[] = "fvdkcljx", s5[] = "-1231";

	strHashTable hT;
	hT.init();
	hT.push(s1);
	hT.push(s2);
	hT.push(s3);
	hT.push(s4);
	hT.push(s5);
	printf("finding s1,2,3,4,5: %d %d %d %d %d\n", hT.find(s1), hT.find(s2), hT.find(s3), hT.find(s4), hT.find(s5));
	hT.del(s3);
	printf("finding s1,2,3,4,5: %d %d %d %d %d\n", hT.find(s1), hT.find(s2), hT.find(s3), hT.find(s4), hT.find(s5));

	return 0;
}