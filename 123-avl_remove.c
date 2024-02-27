#include "binary_trees.h"

/**
 * bal - bal
 * @tree: tree
 * Return: bal
 */
void bal(avl_t **tree)
{
	int int1;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->right == NULL && (*tree)->left == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	int1 = binary_tree_balance((const binary_tree_t *)*tree);
	if (int1 < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
	else if (int1 > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
}
/**
 * successor - successor
 * @node: tree
 * Return: min value
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 *remove_type - remove_type
 *@root: root
 *Return: value
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - bst_remove
 * @root: root
 * @value: value
 * Return: tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value > root->n)
		bst_remove(root->right, value);
	else if (value < root->n)
		bst_remove(root->left, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - avl_remove
 * @root: root
 * @value: value
 * Return: tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
