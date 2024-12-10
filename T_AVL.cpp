#include "Header.h"

int find_h(node_AVL* cur)
{
	return cur == NULL ? -1 : cur->h;
}

void update_h(node_AVL* cur)
{
	cur->h = max(find_h(cur->left), find_h(cur->right)) + 1;
}

int get_balance(node_AVL* cur)
{
	return (cur == NULL) ? 0 : find_h(cur->right) - find_h(cur->left);
}

void swap_AVL(node_AVL* a, node_AVL* b)
{
	int bc = a->val;
	a->val = b->val;
	b->val = bc;
}

void r_rotate(node_AVL* cur)
{
	swap_AVL(cur, cur->left);
	node_AVL* bc = cur->right;
	cur->right = cur->left;
	cur->left = cur->left->left;
	cur->right->left = cur->right->right;
	cur->right->right = bc;

	update_h(cur->right);
	update_h(cur);
}

void l_rotate(node_AVL* cur)
{
	swap_AVL(cur, cur->right);
	node_AVL* bc = cur->left;
	cur->left = cur->right;
	cur->right = cur->right->right;
	cur->left->right = cur->left->left;
	cur->left->left = bc;

	update_h(cur->left);
	update_h(cur);
}

void balance(node_AVL* cur)
{
	int bal = get_balance(cur);
	if (bal == -2)
	{
		if (get_balance(cur->left) == 1)
		{
			l_rotate(cur->left);
		}
		r_rotate(cur);
	}
	else if (bal == 2)
	{
		if (get_balance(cur->right) == -1)
		{
			r_rotate(cur->right);
		}
		l_rotate(cur);
	}
}

node_AVL* ins_AVL(node_AVL* cur, int val)
{
	if (cur == NULL)
	{
		cur = new node_AVL;
		cur->val = val;
	}
	else if (cur->val > val)
	{
		cur->left = ins_AVL(cur->left, val);
	}
	else
	{
		cur->right = ins_AVL(cur->right, val);
	}

	update_h(cur);
	balance(cur);
	return cur;
}

node_AVL* set_data_AVL(node_AVL* cur, int len)
{
	/*random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(0, 100);*/

	for (int i = 0; i < len; i++)
	{
		cur = ins_AVL(cur, i);//distribution(generator));
	}
	return cur;
}

node_AVL* del_h(node_AVL* cur)
{
	if (cur->right == NULL)
	{
		return cur;
	}
	return del_h(cur->right);
}

node_AVL* search_AVL(node_AVL* cur, int val)
{
	while (cur != NULL)
	{
		if (cur->val == val) break;
		if (cur->val > val)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}
	return cur;
}

node_AVL* del_AVL(node_AVL* node, int val)
{
	if (node == NULL)
	{
		cout << "удаляемый элемент не найден";
	}
	else if (node->val > val)
	{
		node->left = del_AVL(node->left, val);
	}
	else if (node->val < val) 
	{ 
		node->right = del_AVL(node->right, val); 
	}
	else
	{
		if (node->right == NULL || node->left == NULL)
		{
			node_AVL* bc = node;
			node = node->left == NULL ? node->right : node->left;
			delete bc;
		}
		else
		{
			node_AVL* maxL = del_h(node->left);
			node->val = maxL->val;
			node->left = del_AVL(node->left, maxL->val);
		}
	}
	if (node != NULL)
	{
		update_h(node);
		balance(node);
	}
	return node;
}

void DFS_pre_AVL(node_AVL* root)
{
	if (root == NULL) return;
	cout << root->val << "\n";
	DFS_pre_AVL(root->left);
	DFS_pre_AVL(root->right);
}

void DFS_in_AVL(node_AVL* root)
{
	if (root == NULL) return;
	DFS_in_AVL(root->left);
	cout << root->val << "\n";
	DFS_in_AVL(root->right);
}

void DFS_post_AVL(node_AVL* root)
{
	if (root == NULL) return;
	DFS_post_AVL(root->left);
	DFS_post_AVL(root->right);
	cout << root->val << "\n";
}

void BFS_AVL(node_AVL* root)
{
	if (root == NULL) return;
	queue<node_AVL*> q;
	q.push(root);

	while (!q.empty()) 
	{
		node_AVL* cur = q.front();
		q.pop();

		cout << cur->val << "\n";

		if (cur->left != NULL)
		{
			q.push(cur->left);
		}
		if (cur->right != NULL)
		{
			q.push(cur->right);
		}
	}
}