#include "bintree.h"
#include <stdlib.h>

bintree *search_bintree(bintree *l, int x) 
{
	if (l == NULL)
		return NULL;
	if (l->item == x)
		return l;
	if (x < l->item)
		return search_bintree(l->left, x);
	else
		return search_bintree(l->right, x);
}

bintree *find_minimum(bintree *l)
{
	bintree *min;
	if (l == NULL)
		return NULL;
	
	min = l;
	while (min->left != NULL)
		min = min->left;
	
	return min;
}

void insert_bintree(bintree **l, int x, bintree *parent)
{
	bintree *p; // temp bintree
	if (*l == NULL) {
		p = malloc(sizeof(bintree));
		p->item = x;
		p->right = p->left = NULL;
		p->parent = parent;
		*l = p;
		return;
	}
	if (x > (*l)->item) {
		insert_bintree(&((*l)->right), x, *l);
	}
	else {
		insert_bintree(&((*l)->left), x, *l);
	}
}

void delete_bintree(int x, bintree *parent)
{
	bintree *current = search_bintree(parent, x);
	if (current->left != NULL && current->right != NULL) {
		bintree *exc = find_minimum(current->right);
		current->item = exc->item;
		exc = NULL;
		return;
	}
	else {
		if (current->left == NULL) {
			if (current->parent->left == current)
				current->parent->left = current->right;
			else
				current->parent->right = current->right;
			current->right->parent = current->parent;
			current = NULL;
			return;
		}
		else {
			if (current->parent->left == current)
				current->parent->left = current->left;
			else
				current->parent->right = current->left;
			current->left->parent = current->parent;
			current = NULL;
			return;
		}
	}
}