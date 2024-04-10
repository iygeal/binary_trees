#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * Description: This function deletes an entire binary tree starting from
 * the root node provided. It recursively deletes each node
 * and frees its memory.
 * If the tree is NULL, it does nothing.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* Delete the left subtree */
	binary_tree_delete(tree->left);

	/* Delete the right subtree */
	binary_tree_delete(tree->right);

	/* Free the current node */
	free(tree);
}

