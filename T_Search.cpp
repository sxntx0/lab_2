#include "Header.h"

//дерево поиска

node_S* ins_S(node_S* cur, int val)
{
	if (cur == NULL)
	{
		cur = new node_S;
		cur->val = val;
	}
	else if (cur->val > val)
	{
		cur->left = ins_S(cur->left, val);
	}
	else
	{
		cur->right = ins_S(cur->right, val);
	}
	return cur;
}

node_S* set_data_S(node_S* cur, int len)
{
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(0, 100);

	for (int i = 0; i < len; i++)
	{
		cur = ins_S(cur, distribution(generator));
	}
	return cur;
}

node_S* search(node_S* cur, int val)
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

node_S* del_h(node_S* cur)
{
	if (cur->right == NULL)
	{
		return cur;
	}
	return del_h(cur->right);
}

node_S* del_S(node_S* node, int val)
{
	if (node == NULL)
	{
		cout << "удаляемый элемент не найден";
	}
	else if (node->val > val)
	{
		node->left = del_S(node->left, val);
	}
	else if (node->val < val)
	{
		node->right = del_S(node->right, val);
	}
	else
	{
		if (node->right == NULL || node->left == NULL)
		{
			node_S* bc = node;
			node = node->left == NULL ? node->right : node->left;
			delete bc;
		}
		else
		{
			node_S* maxL = del_h(node->left);
			node->val = maxL->val;
			node->left = del_S(node->left, maxL->val);
		}
	}
	return node;
}

void DFS_pre_S(node_S* root)
{
	if (root == NULL) return;
	cout << root->val << "\n";
	DFS_pre_S(root->left);
	DFS_pre_S(root->right);
}

void DFS_in_S(node_S* root)
{
	if (root == NULL) return;
	DFS_in_S(root->left);
	cout << root->val << "\n";
	DFS_in_S(root->right);
}

void DFS_post_S(node_S* root)
{
	if (root == NULL) return;
	DFS_post_S(root->left);
	DFS_post_S(root->right);
	cout << root->val << "\n";
}

void BFS_S(node_S* root)
{
	if (root == NULL) return;
	queue<node_S*> q;
	q.push(root);

	while (!q.empty()) 
	{
		node_S* cur = q.front();
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