#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
	int element;
	int balance;
	Node* left;
	Node* right;
	Node* parent;
	int height;
};


typedef struct Node* Nodeptr;

class AvlTree
{
	Node* root;
	int rotations;
public:
	AvlTree() { root = nullptr; }
	~AvlTree()
	{
		while (root)
			Delete(root->element);
	}
	void Add(int x);
	void Delete(int x);
	void Search(int x);
	void Show();
	void Save(const char* file_name);
	void inorder(Node* p);
	void print() {
		PrintTree(root);
	}
	void clean_tree() {
		clear(root);
		delete root;
		root = NULL;
	}
	void sort() {
		sortRec(root);
	}

private:
	Node* insert(int x, Nodeptr& p);
	void find(int x, Nodeptr& p);
	Node* del(int k, Node* p);
	int bsheight(Nodeptr p);
	Nodeptr srl(Nodeptr& p);
	Nodeptr drl(Nodeptr& p);
	Nodeptr srr(Nodeptr& p);
	Nodeptr drr(Nodeptr& p);
	int max(int value1, int value2);
	int count_nodes(Nodeptr p);
	Nodeptr findmin(Nodeptr p);
	Nodeptr findmax(Nodeptr p);
	int deletemin(Nodeptr& p);
	void SaveRec(Nodeptr p, std::ofstream& ofs);
	int get_height(Node* p);
	int bfactor(Node* p);
	void fixheight(Node* p);
	int height(Node* root);
	Node* rotateright(Node* p);
	Node* rotateleft(Node* q);
	Node* balance(Node* p);
	Node* removemin(Node* p);
	void PrintTree(Node* x, int h = 0);
	void clear(Node* p)
	{
		if ((p) != NULL) {
			clear(p->left);
			clear(p->right);
		}
	}
	void sortRec(Node* p)
	{
		if (p != NULL)
		{
			sortRec(p->left);
			sortRec(p->right);
		}
	}
};

void AvlTree::Show()
{
	if (root == NULL)
	{
		cout << " Tree isn't create" << endl;
	}
	inorder(root);
}
void AvlTree::Add(int x) {
	root = insert(x, root);
}
void AvlTree::Delete(int x) {
	root = del(x, root);
}
void AvlTree::Search(int x) {
	find(x, root);
}
void AvlTree::inorder(Node* p) {
	if (p != NULL)
	{
		inorder(p->left);
		cout << p->element << "\t";
		inorder(p->right);
	}
}
void AvlTree::Save(const char* file_name)
{
	std::ofstream ofs(file_name);
	SaveRec(root, ofs);
	ofs.close();
}

void AvlTree::SaveRec(Nodeptr p, std::ofstream& ofs)
{
	if (p != NULL)
	{
		if (p->left)
		{
			SaveRec(p->left, ofs);
		}
		ofs << " " << p->element;
		if (p->right)
		{
			SaveRec(p->right, ofs);
		}
	}
}

Node* AvlTree::insert(int x, Nodeptr& p)
{
	if (p == NULL)
	{
		p = new Node;
		p->element = x;
		p->left = NULL;
		p->right = NULL;
		p->height = 0;
		if (p == NULL)
		{
			cout << "Out of Space\n" << endl;
		}
	}
	else
	{
		if (x < p->element)
		{
			insert(x, p->left);
			if ((bsheight(p->left) - bsheight(p->right)) == 2)
			{
				if (x < p->left->element)
				{
					p = srl(p);
				}
				else
				{
					p = drl(p);
				}
			}
		}
		else if (x > p->element)
		{
			insert(x, p->right);
			if ((bsheight(p->right) - bsheight(p->left)) == 2)
			{
				if (x > p->right->element)
				{
					p = srr(p);
				}
				else
				{
					p = drr(p);
				}
			}
		}
		/*else
		{
			cout << "Элемет существует\n" << endl;
		}*/
	}
	int m, n, d;
	m = bsheight(p->left);
	n = bsheight(p->right);
	d = max(m, n);
	p->height = d + 1;

	return p;
}

int AvlTree::bsheight(Nodeptr p)
{
	int t;
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		t = p->height;
		return t;
	}
}
Nodeptr AvlTree::srl(Nodeptr& p1)
{
	Nodeptr p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = max(bsheight(p2->left), p1->height) + 1;
	return p2;
}
Nodeptr AvlTree::srr(Nodeptr& p1)
{
	Nodeptr p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = max(p1->height, bsheight(p2->right)) + 1;
	return p2;
}
Nodeptr AvlTree::drl(Nodeptr& p1)
{
	p1->left = srr(p1->left);
	return srl(p1);
}
Nodeptr AvlTree::drr(Nodeptr& p1)
{
	p1->right = srl(p1->right);
	return srr(p1);
}
int AvlTree::max(int value1, int value2)
{
	return ((value1 > value2) ? value1 : value2);
}
int AvlTree::count_nodes(Nodeptr p)
{
	int count = 0;
	if (p != NULL)
	{
		count_nodes(p->left);
		count_nodes(p->right);
		count++;
	}
	return count;
}
Nodeptr AvlTree::findmin(Nodeptr p)
{
	if (p == NULL)
	{
		cout << "В дереве нет элементов\n" << endl;
		return p;
	}
	else
	{
		while (p->left != NULL)
		{
			p = p->left;
			//return p;
		}
		return p;
	}
}
Nodeptr AvlTree::findmax(Nodeptr p)
{
	if (p == NULL)
	{
		cout << "В дереве нет элементов\n" << endl;
		return p;
	}
	else
	{
		while (p->right != NULL)
		{
			p = p->right;
			//return p;
		}
		return p;
	}
}
void AvlTree::find(int x, Nodeptr& p)
{
	if (p == NULL)
	{
		cout << "Простите, но такого элемента нет\n" << endl;
	}
	else
	{
		if (x < p->element)
		{
			find(x, p->left);
		}
		else
		{
			if (x > p->element)
			{
				find(x, p->right);
			}
			else
			{
				cout << "Элемент, который вы искали есть в дереве!\n" << endl;
			}
		}
	}
}

int AvlTree::deletemin(Nodeptr& p)
{
	int c;
	cout << "Выбрано удаление минимального значения\n" << endl;
	if (p->left == NULL)
	{
		c = p->element;
		p = p->right;
		return c;
	}
	else
	{
		c = deletemin(p->left);
		return c;
	}
}

int AvlTree::get_height(Node* p)
{
	return p != nullptr ? p->height : 0;
}

int AvlTree::bfactor(Node* p)
{
	return get_height(p->right) - get_height(p->left);
}

void AvlTree::fixheight(Node* p)
{
	int hl = get_height(p->left);
	int hr = get_height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

int AvlTree::height(Node* root)
{
	if (root == NULL) return 0;
	int hLeft = height(root->left);
	int hRight = height(root->right);
	if (hLeft > hRight) return hLeft + 1;
	else return hRight + 1;
}

Node* AvlTree::rotateright(Node* p)
{
	Node* q = p->left;
	p->left = q->right;
	if (q->right)
		q->right->parent = p;
	q->right = p;
	q->parent = p->parent;
	p->parent = q;
	fixheight(p);
	fixheight(q);
	rotations++;
	return q;
}
Node* AvlTree::rotateleft(Node* q)
{
	Node* p = q->right;
	q->right = p->left;
	if (p->left)
		p->left->parent = q;
	p->left = q;
	p->parent = q->parent;
	q->parent = p;
	fixheight(q);
	fixheight(p);
	rotations++;
	return p;
}

Node* AvlTree::balance(Node* p)
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p;
}

Node* AvlTree::del(int k, Node* p)
{
	if (!p)
		return nullptr;
	if (k < p->element)
		p->left = del(k, p->left);
	else if (k > p->element)
		p->right = del(k, p->right);
	else //  k == p->key
	{
		Node* q = p->left;
		Node* r = p->right;
		delete p;
		if (!r)
			return q;
		Node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

Node* AvlTree::removemin(Node* p)
{
	if (p->left == nullptr)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

void AvlTree::PrintTree(Node* x, int h)
{
	if (h == 0)
	{
		h = 0;
	}
	if (x->right != 0)
		PrintTree(x->right, h + 1);
	for (int i = 0; i < h; ++i)
		std::cout << "     ";
	std::cout << x->element << std::endl;
	if (x->left != 0)
		PrintTree(x->left, h + 1);
}