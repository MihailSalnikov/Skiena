#include <stdio.h>
#include "list.h"


int main() {
    list *lst = NULL;
    insert_list(&lst, 1);
    list *lst_item = search_list(lst, 1);
    delete_list_item(&lst, 1);

    return 0;
} 