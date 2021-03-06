
typedef struct bintree {
	int item;
	struct bintree *parent;
	struct bintree *left;
	struct bintree *right;
} bintree;

bintree *search_bintree(bintree *l, int x);
bintree *find_minimum(bintree *l);
void insert_bintree(bintree **l, int x, bintree *parent);
void delete_bintree(int x, bintree *parent);