/* List.
Usage: 
    list *lst = NULL;
    insert_list(&lst, 1);
    list *lst_item = search_list(lst, 1);
    delete_list_item(&lst, 1);
*/

typedef struct list {
    int item;
    struct list *next;
} list;

list *search_list(list *l, int x); // Recursive search in list

void insert_list(list **l, int x);

list *predecessor_list(list *l, int );

void delete_list_item(list **l, int x);