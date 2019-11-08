#define MAX_NODES 10000
#define MAX_BUCKET 17
#include <iostream>
using namespace std;
int mystrcmp(const char*s1, const char*s2);
void mystrcpy(char* dest, const char* src);
////////////////////////////////////
//hash table for string as a key////
//plus deletion of a node///////////
////////////////////////////////////
template <typename t>
void _swap(t &a, t &b) {
	t temp = a;
	a = b;
	b = temp;
}
typedef struct hashNode {
	char id[20];
	char pwd[20];
	hashNode* prev;
	hashNode* next;
	hashNode() :prev(0), next(0) {}
}hashNode;
hashNode static_hash_nodes[MAX_NODES];
int static_hash_idx = 0;
hashNode* static_hash_alloc() {
	return &static_hash_nodes[static_hash_idx++];
}

typedef struct hashTable {
	hashNode *bucket[MAX_BUCKET];
	int totalCnt;

	void init() {
		this->totalCnt = 0;
		for (int i = 0; i < MAX_BUCKET; i++) bucket[i] = 0;
	}
	void push(const char* _id, const char* _pwd) {
		hashNode *temp = static_hash_alloc();
		mystrcpy(temp->id, _id);
		mystrcpy(temp->pwd, _pwd);
		int h = hash(_id);
		if (bucket[h] == 0) bucket[h] = temp;
		else {
			temp->next = bucket[h];
			bucket[h]->prev = temp;
			bucket[h] = temp;
		}
		this->totalCnt++;
	}
	hashNode* findBucket(const char* _id) {
		int h = hash(_id);
		return bucket[h];
	}

	void del(const char*_id) {
		int h = hash(_id);
		hashNode* cur = bucket[h];
		while (cur != 0) {
			if (strcmp(cur->id, _id) == 0) break;
			cur = cur->next;
		}
		if (cur == 0) {
			cout << "no such item" << endl;
			return;
		}
		// When cur is the first and only node of the bucket
		if (cur->prev == 0 && cur->next == 0) bucket[h] = 0;
		// When cur is the first node of the bucket with following nodes
		else if (cur->prev == 0 && cur->next != 0) {
			cur->next->prev = 0;
			bucket[h] = cur->next;
		}
		// WHen cur is a node in the middle of other nodes
		else {
			hashNode* prev = cur->prev;
			hashNode* next = cur->next;
			prev->next = next;
			next->prev = prev;
		}
		cout << "node " << _id << " deleted." << endl;
	}
	int findPwd(const char*_id, char* toSave) {
		hashNode* cur = findBucket(_id);
		if (cur == 0) {
			cout << "node " << _id << " not found" << endl;
			return 0;
		}
		else {
			while (cur != 0) {
				if (mystrcmp(cur->id, _id) == 0) {
					mystrcpy(toSave, cur->pwd);
					return 1;
				}
				cur = cur->next;
			}
		}
		return 0;
	}
	int hash(const char *str) {
		unsigned long h = 5381;
		while (*str != '\0') h = ((h >> 5) + h + *str++) % MAX_BUCKET;
		return (int)h;
	}
}hashTable;

hashTable hT;
int main() {
	char saveBuff[20] = "";
	hT.init();
	hT.push("gun0317", "5201");
	hT.push("xlsh0317@naver.com", "X..!");
	hT.push("gun0317@g.skku.edu", "3!");
	hT.push("oh wow deamon", "deamonon");

	if (hT.findPwd("xlsh0317@naver.com", saveBuff))
		cout << "I found pwd for xlsh0317@naver.com: " << saveBuff << endl;
	hT.del("xlsh0317@naver.com");
	if(hT.findPwd("xlsh0317@naver.com", saveBuff))
		cout << "I found pwd for xlsh0317@naver.com: " << saveBuff << endl;
	if(hT.findPwd("gun0317@g.skku.edu", saveBuff))
		cout << "I found pwd for gun0317@g.skkku.edu: " << saveBuff << endl;

	return 0;
}

int mystrcmp(const char*s1, const char*s2) {
	while (*s2 != '\0') {
		if (*s1 > *s2) return 1;
		else if (*s1 < *s2)return -1;
		s1++, s2++;
	}
	if (*s1 != '\0') return 1;
	return 0;
}
void mystrcpy(char* dest, const char* src) {
	for (; *src != '\0'; *dest++ = *src++);
}