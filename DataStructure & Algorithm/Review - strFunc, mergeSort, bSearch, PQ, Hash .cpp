#define MAX_SIZE 100
#define BUCKET_SIZE 5
#include <iostream>
using namespace std;
// reviewing: 
// done: string functions, strtoint, inttostr, mergeSort, binarySearch, Priority Queue(max heap), Hash

// SWAP anything!
template <typename _t>
void _swap(_t &a, _t &b) {
	_t temp = a;
	a = b;
	b = temp;
}

struct NODE {
	int item;
	NODE* nextNode;
}static_allocated_nodes[MAX_SIZE];
int static_alloc_idx = 0;
NODE* static_alloc() {
	return &static_allocated_nodes[static_alloc_idx++];
}

struct Hash {
private:
	NODE* bucket[BUCKET_SIZE];
	int hash(unsigned long key) {
		unsigned long h = 5381;
		h = ((h >> 5) + h + key) % BUCKET_SIZE;
		return (int)h;
	}
public:
	void init() {
		for (int i = 0; i < BUCKET_SIZE; i++) 
			bucket[i] = 0;
	}

	int find(int target) {
		int h = hash(target);
		NODE* cur = bucket[h];
		if (cur == 0) return 0;
		else 
			while (cur != 0) {
				if (target == cur->item) return 1;
				cur = cur->nextNode;
			}
		return 0;
	}
	void push(int item) {
		int h = hash(item);
		NODE* newOne = static_alloc();
		newOne->item = item, newOne->nextNode = 0;
		if (bucket[h] == 0)
			bucket[h] = newOne;
		else {
			newOne->nextNode = bucket[h]->nextNode;
			bucket[h]->nextNode = newOne;
		}
	}
};

struct minHEAP {
private:
	int heap[MAX_SIZE];
	int heapSize = 0;
public:
	void push(int item) {
		if (heapSize == MAX_SIZE) return;
		heap[heapSize] = item;
		int curIdx = heapSize, parentIdx = (curIdx - 1) / 2;
		while (curIdx >0 /*&& ??*/) {
			if (heap[curIdx] < heap[parentIdx]) {
				_swap(heap[curIdx], heap[parentIdx]);
				curIdx = parentIdx;
			}
			else break;
		}
		heapSize++;
	}

	int pop() {
		int temp = heap[0];
		heap[0] = heap[--heapSize];
		int curIdx = 0, LChildIdx = 1, RChildIdx = 2, childIdx;
		while (LChildIdx < heapSize) {
			if (RChildIdx == heapSize) childIdx = LChildIdx;
			else if (heap[LChildIdx] > heap[RChildIdx]) childIdx = RChildIdx;
			else childIdx = LChildIdx;
			if (heap[curIdx] < heap[childIdx]) break;
			else {
				_swap(heap[curIdx], heap[childIdx]);
				curIdx = childIdx;
			}
			LChildIdx = curIdx * 2 + 1;
			RChildIdx = curIdx * 2 + 2;
		}
		return temp;
	}

	void heapSort(int* list, int len) {
		for (int i = 0; i < len; i++) push(list[i]);
		for (int i = 0; i < len; i++) list[i] = pop();
	}
};

//strfunctions
int _strlen(const char* str) {
	int len = 0;
	while (*str++ != '\0') len++;
	cout << "strlen(" << str << ") is " << len << endl;
	return len;
}

int _strcmp(const char* s1, const char* s2) {
	while (*s1 != '\0' && *s2 != '\0') {
		if (*s1 > *s2) return 1;
		else if (*s2 > *s1) return -1;
		s1++, s2++;
	}
	if(*s1 != '\0') return 1;
	else if (*s2 != '\0') return -1;
	else return 0;
}

void _strcpy(char* dest, const char* src) {
	while (*src != '\0') *dest++ = *src;
}

void _strcat(char* dest, const char* src) {
	while (*dest++ != '\0');
	for (--dest; *src != '\0'; *dest++ = *src++);
}

//strToInt, intToStr
int strToInt(const char* str) {
	int toReturn = 0;
	while (*str != '\0')
		toReturn = toReturn * 10 + *str++ - '0';
	return toReturn;
}

char* intToStr(int num, char* toSave) {
	// (Reversed)
	int len = 0;
	char* temp = toSave;
	while (num > 0) {
		*toSave++ = num % 10 + '0';
		num /= 10;
		len++;
	}
	// Reversing the list
	//************ Pointer that moved cannot be restored
	for (int i = 0; i < len / 2; i++)
		_swap(temp[i], temp[len - 1 - i]);
	return temp;
}

// for ascending order, 오름차순일때
int binarySearch(int* list, int len, int target) {
	int left = 0, right = len - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (list[mid] == target) {
			cout<< "target found."<<endl;
			return 1;
		}
		else if (list[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	cout << "target not found." << endl;
	return 0;
}

// Sorting in ascending order
void merge(int* list, int left, int right) {
	int sorted[MAX_SIZE], mid = (left + right) / 2;
	int first = left, second = mid + 1, idx = left;
	while (first <= mid && second <= right) 
		if (list[first] < list[second]) sorted[idx++] = list[first++];
		else sorted[idx++] = list[second++];
	if (first <= mid)
		for (int i = first; i <= mid; i++) sorted[idx++] = list[i];
	else if (second <= right)
		for (int i = second; i <= right; i++) sorted[idx++] = list[i];
	for (int i = left; i <= right; i++) list[i] = sorted[i];
}

void mergeSort(int* list, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(list, left, mid);
		mergeSort(list, mid + 1, right);
		merge(list, left, right);
	}
}

int main() {
	//int sampleList[8] = { 5,1,3,6,7,2,4,8 };
	//char toSave[20] = "gg";
	//_strcat(toSave, "hihi");
	//cout << toSave <<", "<< _strcmp(toSave, "gghi")<< endl;
	//cout << intToStr(1232141212, toSave) << endl;
	//mergeSort(sampleList, 0, sizeof(sampleList) / sizeof(sampleList[0]) - 1);
	//for (int i = 0; i < 8; i++) cout << sampleList[i] << " ";
	//cout << "\n" << "searching 4(1 means found): " << binarySearch(sampleList, 8, 4) << endl;
	//minHEAP minH;
	//minH.heapSort(sampleList, 8);
	//for (int i = 0; i < 8; i++) cout << sampleList[i] << " ";
	Hash h; h.init();
	for (int i = 1; i < 10; i++) 
		h.push(i);
	printf("Finding 1, 3, 11: %d, %d, %d (1 is found, 0 is not)\n", h.find(1), h.find(3), h.find(11));




	return 0;
}