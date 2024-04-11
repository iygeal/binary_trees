#include "binary_trees.h"
/**
 * binary_tree_nodes - Counts nodes with at least one child
 * @tree: Pointer to root node of the binary tree
 * Return: Number of nodes with at least one child, or 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_child = 0, right_child = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		return (1);

	left_child = tree->left ? binary_tree_nodes(tree->left) : 0;
	right_child = tree->right ? binary_tree_nodes(tree->right) : 0;

	return (left_child + right_child);
}
