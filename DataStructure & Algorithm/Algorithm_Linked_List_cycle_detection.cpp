#include <iostream>
///////////////////////
///Cycle Detection/////
//Using Indegree info//
///////////////////////
using namespace std;

typedef struct NODE {
	int indegree, data;
	NODE* next;
	NODE(int item) {
		this->data = item;
		this->indegree = 0;
		this->next = 0;
	}
}NODE;

class Linked_List {
private:
	int totalCnt;
public:
	NODE* head;
	void init() {
		this->head = 0;
		this->totalCnt = 0;
	}

	void push_back(int item) {
		NODE* cur = this->head;
		NODE* newNode = new NODE(item);
		if (cur == 0) {
			this->head = newNode;
		}
		else {
			this->head = newNode;
			newNode->next = cur;
		}
		this->totalCnt++;
	}

	void printList() {
		NODE* cur = this->head;
		if (cur == 0) {
			cout << "list is empty" << endl;
			return;
		}
		else {
			cout << "Total Item count: " << this->totalCnt << endl;
			cout << "Printing List start" << endl; 
			while (cur != 0) {
				cout << "Printing Node: " << cur->data << endl;
				cur = cur->next;
			}
			cout << "Printing List done" << endl;
		}
	}

	NODE* search(int item) {
		NODE* cur = this->head;
		NODE* prev = cur;
		int index = 0, found = 0;
		if (cur == 0) {
			cout << "list is empty" << endl;
			return 0;
		}
		else {
			while (cur != 0) {
				if (cur->data == item) {
					cout << "node " << item << " found. Index is: " << index << endl;
					found++;
					break;
				}
				prev = cur;
				cur = cur->next;
				index++;
			}
		}
		if (found == 0) {
			cout << "node " << item << " not found" << endl;
			return 0;
		}
		return prev;
	}

	void delete_item(int item) {
		NODE* prev = search(item);
		if (prev == 0) {
			cout << "No such item to delete: " << item << endl;
			return;
		}
		if (prev->next->next != NULL) {
			prev->next = prev->next->next;
		}
		else {
			prev->next = 0;
		}
		cout << "Item deleted: " << item << endl;
		this->totalCnt--;
	}

	void detectCycle() {
		NODE* cur = this->head;
		NODE* prev = cur;
		if (cur == 0) {
			cout << "List is empty" << endl;
			return;
		}
		else {
			while (cur != 0) {
				if (cur->indegree > 0) {
					cout << "Cycle Detected in the list with item: "<< prev->data << endl;
					prev->next = 0;
					indegree_zeroing();
					return;
				}
				prev = cur;
				cur->indegree++;
				cur = cur->next;
			}
		}
		cout << "No cycle detected in the list" << endl;
		indegree_zeroing();
	}

	void indegree_zeroing() {
		NODE* cur = this->head;
		if (cur == 0) {
			cout << "List is empty" << endl;
			return;
		}
		else {
			while (cur != 0) {
				if (cur->indegree > 0) {
					cur->indegree = 0;
				}
				cur = cur->next;
			}
		}
	}
};

int main() {
	Linked_List l;
	l.init();
	l.push_back(5);
	l.push_back(7);
	l.push_back(1);
	l.push_back(3);
	l.push_back(6);
	l.push_back(4);
	l.push_back(9);
	l.printList();
	//l.delete_item(5);
	//l.printList();
	l.detectCycle();
	// create cycle
	l.head->next->next->next = l.head->next;
	// l.printList();	// infinite loop
	l.detectCycle();
	l.detectCycle();
	l.printList();

	return 0;
}