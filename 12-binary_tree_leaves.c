#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the leaves
 *
 * Return: Number of leaves in the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_leaves = 0, right_leaves = 0;

	if (tree == NULL)
		return (0);

	/* If node has no child, it's a leaf, return 1 to count 1 */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Recursively call the function on all the children */
	left_leaves = binary_tree_leaves(tree->left);
	right_leaves = binary_tree_leaves(tree->right);

	/* Return sum of the counts - number of leaf nodes in the tree */
	return (left_leaves + right_leaves);
}
