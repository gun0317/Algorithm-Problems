#include "redblacktree.h"
#include <stdio.h>
#include <stdlib.h>

rbt_tree *test();
void print_preorder(rbt_node *x);
void print_inorder(rbt_node *x);

int main() {
	rbt_tree *T = test();
	print_preorder(T->root);
	printf("\n");
	print_inorder(T->root);
	printf("\n");

	return 0;
}

rbt_tree *test() {
	rbt_tree *T = rbt_create();
	int n, tmp;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &tmp);
		insert(T, tmp);
	}
	return T;
}

void print_preorder(rbt_node *x) {
	if (x == NIL) return;
	if(x->color == RED) printf("-%d-", x->key);
	else printf("<%d>", x->key);
	print_preorder(x->left);
	print_preorder(x->right);
}

void print_inorder(rbt_node *x) {
	if (x == NIL) return;
	print_inorder(x->left);
	if (x->color == RED) printf("-%d-", x->key);
	else printf("<%d>", x->key);
	print_inorder(x->right);
}