#include "binary_trees.h"
/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the binary tree
 * Return: Size of the tree or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size = 0, right_size = 0;

	if (tree == NULL)
		return (0);

	left_size = tree->left ? binary_tree_size(tree->left) : 0;
	right_size = tree->right ? binary_tree_size(tree->right) : 0;

	return ((left_size + right_size) + 1);
}
