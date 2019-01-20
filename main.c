#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "bintree.h"


int main() {
	// list
    list *lst = NULL;
    insert_list(&lst, 1);
    list *lst_item = search_list(lst, 1);
    delete_list_item(&lst, 1);
    // end list

    // bintree
    bintree *btree;
    btree = malloc(sizeof(btree));
    btree->item = 3;
    insert_bintree(&btree, 1, btree);
    insert_bintree(&btree, 2, btree);
    bintree *btree2 = search_bintree(btree, 2);
    printf("%d\n", btree2->item);
    // end bintree

    return 0;
} 