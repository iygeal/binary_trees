#include "binary_trees.h"
/**
 * binary_tree_is_root - Checks if node is a root
 * @node: The node to check
 * Return: 1 if node is a root, 0 otherwise
 * Description: If a node's parent is NULL and node is not NULL, it's a root
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (1); /* Node is the root since it has no parent */

	return (0);
}
