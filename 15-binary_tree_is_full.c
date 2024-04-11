#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_full, right_full;

	if (tree == NULL)
		return (1); /* Empty tree is considered full */

	if (tree->left == NULL && tree->right == NULL)
		return (1); /* Leaf nodes are also considered full */

	if (tree->left != NULL && tree->right != NULL)
	{
		/* If both children are present, recursively check if they are full*/
		left_full = binary_tree_is_full(tree->left);
		right_full = binary_tree_is_full(tree->right);

		/* Return 1 if both subtrees are full, otherwise return 0 */
		return (left_full && right_full);
	}
	else
		/* If the current node has only one child, it's not full */
		return (0);
}
