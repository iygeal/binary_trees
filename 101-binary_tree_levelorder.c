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
/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function traverses the binary tree using level-order
 *  traversal and calls the provided function for each node.
 *  The value in each node is passed as a parameter to the function.
 *  If either tree or func is NULL, the function does nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	int front = 0, rear = 0;

	if (!tree || !func)
		return;

	/* Allocate memory for the queue */
	queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
	if (!queue)
		return;

	/* Enqueue the root node */
	queue[rear++] = (binary_tree_t *)tree;

	/* Continue traversal until the queue is empty */
	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		/* Call the provided function for the current node */
		func(current->n);

		/* Enqueue the left child if it exists */
		if (current->left)
			queue[rear++] = current->left;

		/* Enqueue the right child if it exists */
		if (current->right)
			queue[rear++] = current->right;
	}

	/* Free the memory allocated for the queue */
	free(queue);
}
