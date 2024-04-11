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
	 */
	left_height = binary_tree_height(tree->left);

	/* Recursively calculate the height of the right subtree */
	right_height = binary_tree_height(tree->right);

	/*
	 * Return the maximum height between the left and right subtrees,
	 * plus 1 for the current node
	 */
	return (left_height > right_height ? left_height + 1 : right_height + 1);
}
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
/**
 * binary_tree_is_perfect - Checks if binary tree is perfect
 * @tree: A pointer to the root node of the binary tree
 * Return: 1 if tree is perfect, or 0 if not
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = 0, size = 0;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	/* A binary tree is perefct if 2^height - 1 = its size */
	return (size == (1 << height) - 1);
}
