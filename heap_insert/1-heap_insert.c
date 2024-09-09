#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *parent = NULL;
	heap_t *current = NULL;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	current = *root;
	while (current)
	{
		parent = current;
		if (current->n < value)
			current = current->left;
		else
			current = current->right;
	}

	new_node->parent = parent;
	if (parent->n < value)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}