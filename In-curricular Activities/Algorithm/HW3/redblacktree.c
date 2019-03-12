#include "redblacktree.h"
#include <stdio.h>

// Freely fill your code here.
//struct rbt_node {
//	int key;
//	rbt_node *parent;
//	rbt_node *left;
//	rbt_node *right;
//	rbt_color color;
//};
//
//struct rbt_tree {
//	rbt_node *root;
//};

void rotate_left(rbt_tree *T, rbt_node *x)
{
	rbt_node *y = x->right;
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		T->root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}


void rotate_right(rbt_tree *T, rbt_node *x)
{

	rbt_node *y = x->left;
	x->left = y->right;
	if (y->right != NULL)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		T->root = y;
	else if (x == x->parent->right)
		x->parent->right = y;
	else
		x->parent->left = y;
	y->right = x;
	x->parent = y;
}


rbt_tree *rbt_create()// (1) create and initialize rbt_tree (2) return created rbt_tree
{
	rbt_tree *tree = NULL;
	tree->root = NULL;
	return tree;
}


rbt_node *insert(rbt_tree *T, int key)// (1) create and initialize rbt_node (2) insert rbt_node into rbt_tree. you can just call insert_rbt (3) return created rbt_node
{
	rbt_node *y;
	y->key = key;
	insert_rbt(T, y);
	return y;
}


void insert_rbt(rbt_tree *T, rbt_node *z)
{
	rbt_node *y = NULL;
	rbt_node *x = T->root;
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NULL)
		T->root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
	z->left = NULL;
	z->right = NULL;
	z->color = RED;
	insert_rbt_fixup(T, z);
}


void insert_rbt_fixup(rbt_tree *T, rbt_node *z)
{
	rbt_node *y;
	while (z->color = RED)
	{
		if (z->parent == z->parent->parent->left)
		{
			y = z->parent->parent->right;
			if (y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else if (z == z->parent->right)
			{
				z = z->parent;
				rotate_left(T, z);
			}
			z->parent->color = BLACK;
			z->parent->parent->color = RED;
			rotate_right(T, z);
		}//Left

		else
		{
			y = z->parent->parent->left;
			if (y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else if (z == z->parent->left)
			{
				z = z->parent;
				rotate_right(T, z);
			}
			z->parent->color = BLACK;
			z->parent->parent->color = RED;
			rotate_left(T, z);
		}


	}
	T->root->color = BLACK;
}