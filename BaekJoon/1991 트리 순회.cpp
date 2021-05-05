#include <iostream>

using namespace std;

typedef struct Node {
	char name;
	char left;
	char right;
}node;

node tree[100];

void in(char root) {
	if (root == '.') return;
	else {
		cout << root;
		in(tree[root].left);
		in(tree[root].right);
	}
}

void pre(char root) {
	if (root == '.') return;
	pre(tree[root].left);
	cout << root;
	pre(tree[root].right);
}


void post(char root) {
	if (root == '.') return;
	else {
		post(tree[root].left);
		post(tree[root].right);
		cout << root;
	}
}

int main() {
	int N; cin >> N;
	for (int cnt = 0; cnt < N; cnt++) {
		// root, Lchild, Rchild ordered input
		char input[3];
		cin >> input[0] >> input[1] >> input[2];
		
		tree[input[0]].name = input[0];
		tree[input[0]].left = input[1];
		tree[input[0]].right = input[2];
	}

	in('A');
	cout << endl;
	pre('A');
	cout << endl;
	post('A');


	return 0;
}