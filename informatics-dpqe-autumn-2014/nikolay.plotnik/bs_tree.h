#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#define MAX_NODE_NUMBER 15

enum SIDE_FROM_PARENT { LEFT, RIGHT, UNKNOWN };

//Key will be the pointer to structure itself
struct node {
	char data;
	struct node* parent;
	struct node* left;
	struct node* right;
};

void print_node(struct node* node_to_print);
struct node* insert(struct node* root, char data);
struct node* get_min_for_node(struct node* any_node);
struct node* get_max_for_node(struct node* any_node);
struct node* get_min(struct node* root);
struct node* get_max(struct node* root);
struct node* get_successor(struct node* root);
struct node* get_predecessor(struct node* root);
struct node* get_root(struct node* any_node);
struct node* delete(struct node* node_to_remove);
void print_tree(struct node* root);
void free_memory(struct node* root);

struct node* generate_tree();
void test_tree();

#endif
