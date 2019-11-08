////////////////////////
//////PriorityQueue/////
////////20190720////////
/////////YGun///////////
////////////////////////
#define HEAP_SIZE 100
#include <iostream>
using namespace std;

typedef struct HEAP {
private:
	int heap[HEAP_SIZE];
	int heapSize = 0;
public:
	void init() {
		heapSize = 0;
	}
	// push the new node at the last position
	// check the parent's value and relocate its position
	// Overall procedure: 
	// push new node, check the heap[curIdx] and heap[parentIdx] 
	// if heap[curIdx] > heap[parentIdx], swap and curIdx = parentIdx
	// Finally, increase heapSize by 1.
	// Max heap
	void push(int item) {
		if (heapSize + 1 == HEAP_SIZE) cout << "heap is full";
		// Add the item to the new node
		heap[heapSize] = item;

		int curIdx = heapSize, parentIdx = (curIdx-1)/2;
		// only when it is not a root
		// && when its parent's value is smaller than child
		while (curIdx > 0 && heap[curIdx] > heap[parentIdx]) {
			swap(heap[curIdx], heap[parentIdx]);
			curIdx = parentIdx;
			parentIdx = (curIdx - 1) / 2;
		}
		heapSize++;
	}
	// overall procedure:
	// return the root node and locate the last node to root
	// and the node goes down(unlike pushing) 
	// **heapSize can be reduced prior to these procedure.
	void pop(int &toReturn) {
		if (heapSize <= 0)cout << "heap is empty" << endl;
		toReturn = heap[0];
		// heap[heapSize] is next to the last element, so we need to pop [--heapSize]
		heap[0] = heap[--heapSize];
		int curIdx = 0, leftChildIdx = 1, rightChildIdx = 2, childIdx;
		// Only when there is a child(at least left one)
		while (leftChildIdx < heapSize) {
			// When there is no right child -> select left child
			if (rightChildIdx == heapSize)
				childIdx = leftChildIdx;
			// When there are both children -> select the bigger one
			else
				childIdx = heap[leftChildIdx] > heap[rightChildIdx] ? leftChildIdx : rightChildIdx;
			// Swap current node with child if child is larger
			if (heap[curIdx] > heap[childIdx])
				break;
			else
				swap(heap[curIdx], heap[childIdx]);
			// Now current node's index = (what was) child.
			// Need to update the children indexes for next itertation.
			curIdx = childIdx;
			leftChildIdx = curIdx * 2 + 1;
			rightChildIdx = leftChildIdx + 1;
		}
	}
}HEAP;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int T, N;
	HEAP h; 
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);
		h.init();
		for (int i = 0; i < N; i++)
		{
			int value;
			scanf("%d", &value);
			h.push(value);
		}

		printf("#%d ", test_case);

		for (int i = 0; i < N; i++)
		{
			int value;
			h.pop(value);
			printf("%d", value);
			printf(" ");
		}
		printf("\n");
		printf(" ");
	}
	return 0;
}


