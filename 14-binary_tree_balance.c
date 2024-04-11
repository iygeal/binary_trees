#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	/*
	 *Recursively calculate the height of the left subtree
	 * The ternary operator takes care of when the current node is a leaf node
	 * If it is, the node contributes 0 to the height
	 */
	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;

	/* Recursively calculate the height of the right subtree */
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	/*
	 * Return the maximum height between the left and right subtrees,
	 * plus 1 for the current node
	 */
	return (left_height > right_height ? left_height : right_height);
}
/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Balance factor or 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = (int)binary_tree_height(tree->left);
	right_height = (int)binary_tree_height(tree->right);

	return (left_height - right_height);
}
