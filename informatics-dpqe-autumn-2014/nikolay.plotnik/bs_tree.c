#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bs_tree.h"
#include <time.h>

void print_node(struct node* node_to_print) {
	printf("Node - %p\t", node_to_print);
	if (node_to_print != NULL) {
		printf("parent - %p, left - %p, right - %p, data - %c\t\t", node_to_print->parent, node_to_print->left, node_to_print->right, node_to_print->data);
	}
}

struct node* insert(struct node* root, char data) {
	struct node* last = NULL;
	struct node* new_node = NULL;
	struct node* tmp = root;

	if ((new_node = (struct node*)calloc(1, sizeof(struct node))) == NULL) {
		printf("Unable to allocate memory for new tree node\n");
		return NULL;
	}

	new_node->data = data;

	while (tmp != NULL) {
		last = tmp;
		if (new_node < tmp) {
			tmp = tmp->left;
		}
		else {
			tmp = tmp->right;
		}
	}

	new_node->parent = last;


	printf("Inserting node: ");
	print_node(new_node);
	printf("\n");

	if (last == NULL) {
		return new_node;
	}

	if (new_node < last) {
		last->left = new_node;
	}
	else {
		last->right = new_node;
	}

	return root;
}

struct node* get_min_for_node(struct node* any_node) {
	struct node* tmp = any_node;

	if (any_node == NULL)
		return NULL;

	while (tmp->left != NULL)
		tmp = tmp->left;

	return any_node != tmp ? tmp : NULL;
}

struct node* get_max_for_node(struct node* any_node) {
	struct node* tmp = any_node;

	if (any_node == NULL)
		return NULL;

	while (tmp->right != NULL)
		tmp = tmp->right;

	return any_node != tmp ? tmp : NULL;
}

struct node* get_min(struct node* any_node) {
	return get_min_for_node(get_root(any_node));
}

struct node* get_max(struct node* any_node) {
	return get_max_for_node(get_root(any_node));
}

struct node* get_successor(struct node* any_node) {
	struct node* successor = NULL;

	if (any_node == NULL)
		return NULL;
	
	if (any_node->right != NULL) {
		if ((successor = get_min_for_node(any_node->right)) != NULL) {
			return successor;
		}
		return any_node->right;
	}

	successor = any_node->parent;
	while ((successor != NULL) && (successor->right == any_node)) {
		any_node = successor;
		successor = successor->parent;
	}

	return successor;
}

struct node* get_predecessor(struct node* any_node) {
	struct node* predecessor = NULL;

	if (any_node == NULL)
		return NULL;

	if (any_node->left != NULL) {
		if ((predecessor = get_max_for_node(any_node->left)) != NULL) {
			return predecessor;
		}
		return any_node->left;
	}

	predecessor = any_node->parent;
	while ((predecessor != NULL) && (predecessor->left == any_node)) {
		any_node = predecessor;
		predecessor = predecessor->parent;
	}

	return predecessor;
}

struct node* get_root(struct node* any_node) {
	if (any_node == NULL)
		return NULL;

	while (any_node->parent != NULL)
		any_node = any_node->parent;

	return any_node;
}

static struct node* delete_node_with_no_more_than_one_child(struct node* any_node) {
	struct node* root = NULL;
	struct node* orphaned_subtree = NULL;

	if (any_node->left != NULL) {
		orphaned_subtree = any_node->left;
		any_node->left = NULL;
	}
	else if (any_node->right != NULL) {
		orphaned_subtree = any_node->right;
		any_node->right = NULL;
	}

	if (orphaned_subtree != NULL) {
		orphaned_subtree->parent = any_node->parent;
	}

	if (any_node->parent == NULL) {
		root = orphaned_subtree;
	}
	else {
		if (any_node->parent->left == any_node) {
			any_node->parent->left = orphaned_subtree;
		}
		else {
			any_node->parent->right = orphaned_subtree;
		}
		root = get_root(any_node);
		any_node->parent = NULL;
	}

	return root;
}

struct node* delete(struct node* node_to_remove) {
	struct node* successor = NULL;
	struct node* root = NULL;

	if (node_to_remove == NULL)
		return NULL;
	
	if ((node_to_remove->left == NULL) || (node_to_remove->right == NULL)) {
		root = delete_node_with_no_more_than_one_child(node_to_remove);
	} 
	else {
		successor = get_successor(node_to_remove);
		root = delete_node_with_no_more_than_one_child(successor);
		//Here we replace node_to_remove with successor
		successor->parent = node_to_remove->parent;
		if ((node_to_remove->parent != NULL) && (node_to_remove->parent->left == node_to_remove)) {
			node_to_remove->parent->left = successor;
		}
		if ((node_to_remove->parent != NULL) && (node_to_remove->parent->right == node_to_remove)) {
			node_to_remove->parent->right = successor;
		}
		if (node_to_remove->left != NULL) {
			successor->left = node_to_remove->left;
			node_to_remove->left->parent = successor;
		}
		if (node_to_remove->right != NULL) {
			successor->right = node_to_remove->right;
			node_to_remove->right->parent = successor;
		}

		if (root == node_to_remove)
			root = successor;
	}

	free(node_to_remove);

	return root;
}

void print_tree(struct node* root) {
	if (root != NULL) {
		print_tree(root->left);
		print_node(root);
		print_tree(root->right);
	}
}

void free_memory(struct node* root) {
	if (root != NULL) {
		free_memory(root->left);
		free_memory(root->right);
		free(root);
	}
}

struct node* generate_tree() {
	struct node* tree = NULL;
	int node_amount = 0;
	int i = 0;

	srand((unsigned int)time(NULL));
	
	node_amount = (rand() % MAX_NODE_NUMBER) + 1;

	for (i = 0; i < node_amount; i++) {
		if ((tree = insert(tree, (rand() % 26) + 'a')) == NULL) {
			printf("Unable to insert item in the tree\n");
			break;
		}
	}

	return tree;
}

void test_tree() {
	struct node* tree = NULL;
	tree = generate_tree();
	print_tree(tree);
	printf("\n");
	while ((tree = delete(tree)) != NULL) {
		print_tree(tree);
		printf("\n\n\n");
	}
	free_memory(tree);
}

