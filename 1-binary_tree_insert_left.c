#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Check if the parent node is NULL */
	if (parent == NULL)
		return (NULL);

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	/* Set the value and parent of the new node */
	new_node->n = value;
	new_node->parent = parent;

	/* Set the new node's left child to the current left child of the parent */
	new_node->left = parent->left;

	/* Set the new node's right child to NULL */
	new_node->right = NULL;

	/* If the parent already has a left child, adjust its parent pointer */
	if (parent->left != NULL)
		parent->left->parent = new_node;

	/* Set the parent's left child to the new node */
	parent->left = new_node;

	/* Return a pointer to the new node */
	return (new_node);
}
