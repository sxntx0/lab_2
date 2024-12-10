#pragma once
#include <iostream>
#include <random>
#include <queue>
using namespace std;

struct node_S
{
	node_S* left = NULL;
	node_S* right = NULL;
	int val = 0;
};

struct node_AVL
{
	node_AVL* left = NULL;
	node_AVL* right = NULL;
	int val = 0;
	int h = 0;
};

enum Color { RED, BLACK };

struct node_RB {
    int val;
    node_RB* par;
    node_RB* l;
    node_RB* r;
    Color col;

    node_RB(int val)
    {
        this->val = val;
        this->par = nullptr;
        this->l = nullptr;
        this->r = nullptr;
        this->col = RED;
    }
};

//дерево поиска

node_S* ins_S(node_S* root, int val);
node_S* set_data_S(node_S* root, int len);
node_S* search(node_S* cur, int val);
node_S* del_S(node_S* root, int val);

//AVL дерево

node_AVL* ins_AVL(node_AVL* root, int val);
node_AVL* set_data_AVL(node_AVL* cur, int len);
node_AVL* search_AVL(node_AVL* cur, int val);
node_AVL* del_AVL(node_AVL* cur, int val);

//RB дерево

void ins_RB(node_RB*& root, int key);
void set_data_RB(node_RB*& root, int len);
node_RB* search_RB(node_RB* root, int key);
void del_RB(node_RB*& root, int val);

//¬ывод деревьев

void DFS_pre_S(node_S* root);
void DFS_in_S(node_S* root);
void DFS_post_S(node_S* root);
void BFS_S(node_S* root);

void DFS_pre_AVL(node_AVL* root);
void DFS_in_AVL(node_AVL* root);
void DFS_post_AVL(node_AVL* root);
void BFS_AVL(node_AVL* root);

void DFS_pre_RB(node_RB* root);
void DFS_in_RB(node_RB* root);
void DFS_post_RB(node_RB* root);
void BFS_RB(node_RB* root);