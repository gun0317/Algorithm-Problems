#define MAX_NODES 1000
#include <iostream>
using namespace std;
//////////////////////
//Double Linked List//
//Using static alloc//
//////////////////////

//push(item,position), pop(position), print_all()
typedef struct NODE {
	NODE *prev;
	int item;
	NODE *next;
	// constructor
	NODE() : prev(0), item(0), next(0){}
}NODE;
// static allocation
int static_allocation_idx = 0;
NODE static_allocated_nodes[MAX_NODES];
NODE* static_alloc() {
	return &static_allocated_nodes[static_allocation_idx++];
}
//

typedef struct double_linked_list {
	NODE* head;
	NODE* tail;
	int num = 0;
	void init() {
		//head = (NODE*)malloc(sizeof(NODE));
		head = static_alloc();
		tail = static_alloc();
		// item and else things are initialized in constructor
		head->next = tail; 
		tail->prev = head; 
	}
	// Add node right next to the head.
	NODE* add(int _item) {
		this->num++;
		NODE* temp = static_alloc();
		NODE* was_next = head->next;
		temp->item = _item; temp->prev = head; temp->next = was_next;
		was_next->prev = temp; head->next = temp;
		cout << "Node added. Item is " << head->next->item << endl;
		return temp;
	}
	// Find the item in the list(linear)
	NODE* find(int _item) {
		NODE* cur = head->next;
		NODE* temp = static_alloc();
		while (cur->prev != 0 && cur->next != 0) {
			if (cur->item == _item) {
				temp = cur;
				break;
			}
			else 
				cur = cur->next;
		}
		return temp;
	}
	// Delete specific node
	void delete_node(int _item) {
		NODE* target = find(_item);
		if (target->prev != 0 && target->next != 0) {
			target->prev->next = target->next;
			target->next->prev = target->prev;
			this->num--;
			cout << "Node " << _item << " deleted." << endl;
		}
		else {
			cout << "No such item to delete: " << _item << endl;
		}
	}
	// Print all the node in the list
	void print_list() {
		cout << "**Printing**" << endl;
		NODE* cur = head->next;
		int idx = 1;
		for (; cur != tail; cur = cur->next) {
			printf("item of node number %d: %d\n",idx++,cur->item);
		}
		cout << "**End of print**" << endl;
	}
	// Print all the node reversely
	void r_print_list() {
		cout << "**Printing in reverse order**" << endl;
		NODE* cur = tail->prev;
		int idx = 0;
		for (; cur != head; cur = cur->prev) {
			printf("item of node number %d(Reversed): %d\n", num-idx++, cur->item);
		}
		cout << "**End of print**" << endl;
	}
}double_linked_list;



int main() {
	// Initialization
	double_linked_list d_list;
	static_allocation_idx = 0;
	d_list.init();

	// add
	for (int i = 1; i < 15; i *= 2) {
		d_list.add(i);
	}
	// print
	d_list.print_list();
	d_list.r_print_list();

	// find
	for (int i = 0; i < 10; i++) {
		NODE* found = d_list.find(i);
		if (found->next != 0 && found->prev != 0) {
			printf("Node containing %d found!\n", i);
		}
		else {
			cout << "Node containing "<<i<<" not found" << endl;
		}
	}

	// delete
	d_list.delete_node(2);
	d_list.delete_node(3);
	d_list.delete_node(4);

	// print
	d_list.print_list();
	d_list.r_print_list();

	return 0;
}
