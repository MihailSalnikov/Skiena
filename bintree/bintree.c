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

void insert_bintree(bintree **l, int x, bintree *parent)
{
	bintree *p; // temp bintree
	if (*l == NULL) {
		p = malloc(sizeof(bintree));
		p->item = x;
		p->left = p->right = NULL;
		*l = p;
		return;
	}
	if (x < (**l).item)
		insert_bintree(&(**l).left, x, *l);
	else
		insert_bintree(&(**l).right, x, *l);
}