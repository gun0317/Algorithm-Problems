#define MAX 100
#include <stdio.h>

////////////////////////////
///////Circular Queue///////
////////////////////////////

//circular queue -> push, pop, front, tail, isEmpty, isFull
int head = 0, tail = 0, c_queue[MAX];

bool q_isEmpty() {
	if (tail == head)
		return true;
	else
		return false;
}

bool q_isFull() {
	if ((head + 1) % MAX == tail)
		return true;
	else
		return false;
}

void q_push(int item) {
	if (!q_isFull()) {
		c_queue[head++] = item;
		printf("item added to the queue is %d\n", item);
	}
	else
		printf("queue is full\n");
}

int q_peak() {	//returns the first came data
	if (!q_isEmpty())
		return c_queue[tail];
	else
		printf("queue is empty\n");
	return -1;
}

int q_pop() {
	if (!q_isEmpty()) {
		int item = q_peak();
		tail = (tail + 1) % MAX;
		return item;
	}
	else
		printf("queue is empty\n");
	return -1;
}



///////////////////
///////STACK///////
///////////////////

//stack -> push, pop, peak, isEmpty, isFull
int stack[MAX];
int top = -1;

bool s_isEmpty(){
	bool ans;
	top == -1 ? ans = true : ans = false;
	return ans;
}

bool s_isFull() {
	bool ans;
	top == MAX - 1 ? ans = true : ans = false;
	return ans;
}

int s_peak() {
	if (!s_isEmpty()) {
		return stack[top];
	}
	else
		printf("stack is empty\n");
}

int s_pop() {
	if (!s_isEmpty()) {
		int item = s_peak();
		top--;
		return item;
	}
	else {
		printf("stack is empty\n");
		return -1;
	}
}

void s_push(int item) {
	if (!s_isFull())
		stack[++top] = item;
	else
		printf("stack is full\n");
}

int main() {
	s_push(1);
	s_push(2);
	s_push(3);
	s_push(4);
	for (int i = 0; i < 5; i++) 
		printf("%d\n",s_pop());
	
	q_push(5);
	q_push(6);
	q_push(7);
	q_push(8);
	for (int i = 0; i < 5; i++)
		printf("%d\n", q_pop());

	return 0;
}

