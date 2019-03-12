#define NIL NULL

typedef enum { RED, BLACK } rbt_color;

typedef struct rbt_node rbt_node;
typedef struct rbt_tree rbt_tree;

struct rbt_node {
	int key;
	rbt_node *parent;
	rbt_node *left;
	rbt_node *right;
	rbt_color color;
};

struct rbt_tree {
	rbt_node *root;
};

void rotate_left(rbt_tree *T, rbt_node *x);
void rotate_right(rbt_tree *T, rbt_node *x);
rbt_tree *rbt_create();								// (1) create and initialize rbt_tree (2) return created rbt_tree
rbt_node *insert(rbt_tree *T, int key);				// (1) create and initialize rbt_node (2) insert rbt_node into rbt_tree. you can just call insert_rbt (3) return created rbt_node
void insert_rbt(rbt_tree *T, rbt_node *z);
void insert_rbt_fixup(rbt_tree *T, rbt_node *z);