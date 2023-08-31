#include "binary_trees.h"

/**
 * heapify_down - Helper function to heapify down a heap.
 * @heap: Pointer to the root node of the heap.
 */
void heapify_down(heap_t *heap)
{

heap_t *largest = heap;
heap_t *left = heap->left;
heap_t *right = heap->right;

	if (left && left->n > largest->n)
	largest = left;

	if (right && right->n > largest->n)
	largest = right;

if (largest != heap)
{
	int temp = heap->n;

	heap->n = largest->n;
	largest->n = temp;
	heapify_down(largest);
}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: Value stored in the root node or 0 if function fails.
 */
int heap_extract(heap_t **root)
{
int value;

if (!root || !*root)
	return (0);

value = (*root)->n;
heap_t *last_node = *root;
while (last_node->right)

	last_node = last_node->right;

if ((*root)->left)
	(*root)->n = last_node->left->n;
else
(*root)->n = last_node->n;

if (last_node->parent->left == last_node)
last_node->parent->left = NULL;
else
	last_node->parent->right = NULL;

free(last_node);

heapify_down(*root);

return (value);
}
