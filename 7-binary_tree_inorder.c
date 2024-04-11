#include "binary_trees.h"
/**
* binary_tree_inorder - Goes through a binary tree using in-order trasversal
* @tree: Pointer to the root node of the binary tree
* @func: Pointer to a function to call for each node
* Return: Nothing
* Description: In-order trasversal entails checking the left child first,
* then visiting the root before finally checking the right child
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
