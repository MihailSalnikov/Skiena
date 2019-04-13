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
        // Start initialize bintree
    bintree *btree;
    btree = malloc(sizeof(btree));
    btree->item = 3;
    btree->right = btree->left = NULL;
        // End initialize bintree
    insert_bintree(&btree, 2, btree);
    insert_bintree(&btree, 11, btree);
    insert_bintree(&btree, 6, btree);
    insert_bintree(&btree, 5, btree);
    insert_bintree(&btree, 7, btree);
    insert_bintree(&btree, 12, btree);
    insert_bintree(&btree, 13, btree);
    
    bintree *btree2 = search_bintree(btree, 5);
    printf("Find 2: %d\n", btree2->item);
    btree2 = find_minimum(btree);
    printf("Find minimum: %d\n", btree2->item);
    delete_bintree(11, btree);
    btree2 = search_bintree(btree, 11);
    printf("Is 11 in bintree? %s\n", btree2 == NULL ? "true": "false");
    // end bintree

    return 0;
} 