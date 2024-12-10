#include "Header.h"
#include <fstream>

int height_S(node_S* root)
{
	if (root == NULL) return 0;

	return max(height_S(root->left), height_S(root->right)) + 1;
}

int height_AVL(node_AVL* root)
{
	if (root == NULL) return 0;

	return max(height_AVL(root->left), height_AVL(root->right)) + 1;
}

int height_RB(node_RB* root)
{
	if (root == nullptr) return 0;

	return max(height_RB(root->l), height_RB(root->r)) + 1;
}

void delete_S(node_S* root)
{
	if (root == NULL) return;

	delete_S(root->left);
	delete_S(root->right);
	delete root;
}

void delete_AVL(node_AVL* root)
{
	if (root == NULL) return;

	delete_AVL(root->left);
	delete_AVL(root->right);
	delete root;
}

void delete_RB(node_RB* root)
{
	if (root == nullptr) return;

	delete_RB(root->l);
	delete_RB(root->r);
	delete root;
}

int main() 
{
	int len = 100;

	node_S* root_S = NULL;
	node_AVL* root_AVL = NULL;
	node_RB* root_RB = nullptr;

	ofstream F("out_data.txt");

	//for (int i = 0; i <= len; i++)
	//{
	//	/*root_S = set_data_S(root_S, i);
	//	F << i << " " << height_S(root_S) << endl;
	//	delete_S(root_S); root_S = NULL;*/

	//	/*root_AVL = set_data_AVL(root_AVL, i);
	//	F << i << " " << height_AVL(root_AVL) << endl;
	//	delete_AVL(root_AVL); root_AVL = NULL;*/

	//	set_data_RB(root_RB, i);
	//	F << i << " " << height_RB(root_RB) << endl;
	//	delete_RB(root_RB); root_RB = nullptr;
	//}

	root_S = set_data_S(root_S, 10);
	BFS_S(root_S);

	F.close();
	return 0;
}