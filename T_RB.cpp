#include "Header.h"

void r_rotate(node_RB*& root, node_RB* x) 
{
    node_RB* y = x->l;
    x->l = y->r;
    if (y->r != nullptr) 
    {
        y->r->par = x;
    }
    y->par = x->par;
    if (x->par == nullptr) 
    {
        root = y;
    }
    else if (x == x->par->r) 
    {
        x->par->r = y;
    }
    else
    {
        x->par->l = y;
    }
    y->r = x;
    x->par = y;
}

void l_rotate(node_RB*& root, node_RB* x) 
{
    node_RB* y = x->r;
    x->r = y->l;
    if (y->l != nullptr)
    {
        y->l->par = x;
    }
    y->par = x->par;
    if (x->par == nullptr)
    {
        root = y;
    }
    else if (x == x->par->l)
    {
        x->par->l = y;
    }
    else 
    {
        x->par->r = y;
    }
    y->l = x;
    x->par = y;
}

void fix_ins(node_RB*& root, node_RB* z)
{
    while (z != root && z->par->col == RED)
    {
        if (z->par == z->par->par->l) 
        {
            node_RB* y = z->par->par->r;
            if (y != nullptr && y->col == RED)
            {
                z->par->col = BLACK;
                y->col = BLACK;
                z->par->par->col = RED;
                z = z->par->par;
            }
            else 
            {
                if (z == z->par->r)
                {
                    z = z->par;
                    l_rotate(root, z);
                }
                z->par->col = BLACK;
                z->par->par->col = RED;
                r_rotate(root, z->par->par);
            }
        }
        else
        {
            node_RB* y = z->par->par->l;
            if (y != nullptr && y->col == RED)
            {
                z->par->col = BLACK;
                y->col = BLACK;
                z->par->par->col = RED;
                z = z->par->par;
            }
            else
            {
                if (z == z->par->l)
                {
                    z = z->par;
                    r_rotate(root, z);
                }
                z->par->col = BLACK;
                z->par->par->col = RED;
                l_rotate(root, z->par->par);
            }
        }
    }
    root->col = BLACK;
}

void ins_RB(node_RB*& root, int val) 
{
    node_RB* z = new node_RB(val);
    node_RB* y = nullptr;
    node_RB* x = root;

    while (x != nullptr)
    {
        y = x;
        if (z->val < x->val) 
        {
            x = x->l;
        }
        else 
        {
            x = x->r;
        }
    }

    z->par = y;
    if (y == nullptr) 
    {
        root = z;
    }
    else if (z->val < y->val) 
    {
        y->l = z;
    }
    else 
    {
        y->r = z;
    }

    fix_ins(root, z);
}

node_RB* search_RB(node_RB* root, int val) 
{
    while (root != nullptr && root->val != val) 
    {
        if (val < root->val)
        {
            root = root->l;
        }
        else 
        {
            root = root->r;
        }
    }
    return root;
}

void fix_del(node_RB*& root, node_RB* x) 
{
    while (x != root && x != nullptr && x->col == BLACK) 
    {
        if (x == x->par->l) 
        {
            node_RB* w = x->par->r;
            if (w != nullptr && w->col == RED) 
            {
                w->col = BLACK;
                x->par->col = RED;
                l_rotate(root, x->par);
                w = x->par->r;
            }
            if ((w == nullptr || w->l == nullptr || w->l->col == BLACK) &&
                (w == nullptr || w->r == nullptr || w->r->col == BLACK)) {
                if (w != nullptr) 
                {
                    w->col = RED;
                }
                x = x->par;
            }
            else 
            {
                if (w != nullptr && (w->r == nullptr || w->r->col == BLACK)) 
                {
                    if (w->l != nullptr) 
                    {
                        w->l->col = BLACK;
                    }
                    w->col = RED;
                    r_rotate(root, w);
                    w = x->par->r;
                }
                if (w != nullptr) 
                {
                    w->col = x->par->col;
                    x->par->col = BLACK;
                    if (w->r != nullptr) 
                    {
                        w->r->col = BLACK;
                    }
                    l_rotate(root, x->par);
                    x = root;
                }
            }
        }
        else 
        {
            node_RB* w = x->par->l;
            if (w != nullptr && w->col == RED) 
            {
                w->col = BLACK;
                x->par->col = RED;
                r_rotate(root, x->par);
                w = x->par->l;
            }
            if ((w == nullptr || w->r == nullptr || w->r->col == BLACK) &&
                (w == nullptr || w->l == nullptr || w->l->col == BLACK)) {
                if (w != nullptr) 
                {
                    w->col = RED;
                }
                x = x->par;
            }
            else 
            {
                if (w != nullptr && (w->l == nullptr || w->l->col == BLACK)) 
                {
                    if (w->r != nullptr) 
                    {
                        w->r->col = BLACK;
                    }
                    w->col = RED;
                    l_rotate(root, w);
                    w = x->par->l;
                }
                if (w != nullptr) 
                {
                    w->col = x->par->col;
                    x->par->col = BLACK;
                    if (w->l != nullptr) 
                    {
                        w->l->col = BLACK;
                    }
                    r_rotate(root, x->par);
                    x = root;
                }
            }
        }
    }
    if (x != nullptr) 
    {
        x->col = BLACK;
    }
}

void transplant(node_RB*& root, node_RB* u, node_RB* v) 
{
    if (u->par == nullptr) 
    {
        root = v;
    }
    else if (u == u->par->l) 
    {
        u->par->l = v;
    }
    else 
    {
        u->par->r = v;
    }
    if (v != nullptr) 
    {
        v->par = u->par;
    }
}

node_RB* minimum(node_RB* node_RB) 
{
    while (node_RB->l != nullptr) 
    {
        node_RB = node_RB->l;
    }
    return node_RB;
}

void del(node_RB*& root, node_RB* z) 
{
    node_RB* y = z;
    node_RB* x;
    Color originalColor = y->col;

    if (z->l == nullptr) {
        x = z->r;
        transplant(root, z, z->r);
    }
    else if (z->r == nullptr) 
    {
        x = z->l;
        transplant(root, z, z->l);
    }
    else
    {
        y = minimum(z->r);
        originalColor = y->col;
        x = y->r;
        if (y->par == z) 
        {
            if (x != nullptr) 
            {
                x->par = y;
            }
        }
        else 
        {
            transplant(root, y, y->r);
            y->r = z->r;
            y->r->par = y;
        }
        transplant(root, z, y);
        y->l = z->l;
        y->l->par = y;
        y->col = z->col;
    }
    if (originalColor == BLACK) 
    {
        fix_del(root, x);
    }
}

void del_RB(node_RB*& root, int val)
{
    node_RB* del_node = search_RB(root, val);
    if (del_node != nullptr) 
    {
        del(root, del_node);
    }
    else
    {
        cout << "Элемент для удаления не найден";
    }
}

void set_data_RB(node_RB*& root, int len)
{
	/*random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(15, 30);*/

	for (int i = 0; i < len; i++)
	{
        ins_RB(root, i);//distribution(generator));
	}
}

void DFS_pre_RB(node_RB* root)
{
    if (root == nullptr) return;
    cout << root->val << "\n";
    DFS_pre_RB(root->l);
    DFS_pre_RB(root->r);
}

void DFS_in_RB(node_RB* root)
{
    if (root == nullptr) return;
    DFS_in_RB(root->l);
    cout << root->val << "\n";
    DFS_in_RB(root->r);
}

void DFS_post_RB(node_RB* root)
{
    if (root == nullptr) return;
    DFS_post_RB(root->l);
    DFS_post_RB(root->r);
    cout << root->val << "\n";
}

void BFS_RB(node_RB* root)
{
    if (root == nullptr) return;
    queue<node_RB*> q;
    q.push(root);

    while (!q.empty()) 
    {
        node_RB* cur = q.front();
        q.pop();

        cout << cur->val << "\n";

        if (cur->l != nullptr)
        {
            q.push(cur->l);
        }
        if (cur->r != nullptr)
        {
            q.push(cur->r);
        }
    }
}