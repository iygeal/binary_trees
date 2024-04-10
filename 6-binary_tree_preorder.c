#include "binary_trees.h"
/**
 * binary_tree_preorder - Goes through a binary tree in a pre-order trasversal
 * @tree: Pointer to the root node of the binary tree
 * @func: Pointer to a function to call for each node
 * Return: Nothing
 * Description: Pre-order trasversal goes through the root first,
 * then left child and finally, the right child
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
