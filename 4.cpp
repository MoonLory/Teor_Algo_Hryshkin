#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
//long long sum;
struct Node                        
{
	int x, g, h, kol;                           
	Node *l, *r; 
	

};

Node *KOREN = NULL;

void add_node(int x, Node *&MyTree, int g=0)                  
{
	if (NULL == MyTree)                           
	{
		MyTree = new Node;                          
		MyTree->x = x;                             
		MyTree->l = MyTree->r = NULL;        
		MyTree->g = g;
	}

	if (x < MyTree->x)               
	{
		if (MyTree->l != NULL) add_node(x, MyTree->l, g + 1); 
		else                      
		{
			MyTree->l = new Node;                 
			MyTree->l->l = MyTree->l->r = NULL;  
			MyTree->l->x = x; 
			MyTree->l->g = g+1;
		}
	}

	if (x > MyTree->x)          
	{
		if (MyTree->r != NULL) add_node(x, MyTree->r, g + 1); 
		else                                          
		{
			MyTree->r = new Node;                 
			MyTree->r->l = MyTree->r->r = NULL;   
			MyTree->r->x = x;      
			MyTree->r->g = g+1;

		}
	}

}

/*void show(Node *&Tree)              
{
	if (Tree != NULL) {
		sum += Tree->x;
		//cout << (Tree->x) << endl;
		show(Tree->l);
		show(Tree->r);
	}
	
}*/

void lev_obh(Node *&Tree, ostream & fout)
{
	if (Tree != NULL) {
		fout << (Tree->x) << endl;
		lev_obh(Tree->l, fout);
		lev_obh(Tree->r, fout);
	}
	
}

pair<Node*, Node*> find(Node *Tree, Node*parent, int x)
{
	if (Tree == NULL) return make_pair(Tree,parent);

	if (Tree->x > x)
	{
		return find(Tree->l,Tree, x);
	}
	else

	if (Tree->x < x)

		return find(Tree->r,Tree, x);
	else

		return make_pair(Tree, parent);

}


void del(Node *&Tree, int x)
{
	pair<Node*, Node*> fm;
	fm=find(Tree, NULL, x);
	if (fm.first == NULL) return;
	if (fm.first->l == NULL)
		if (fm.second != NULL)
			if (fm.second->l == fm.first) fm.second->l = fm.first->r;
			else
			{
				fm.second->r = fm.first->r;
			}
		else
		{
			Tree = fm.first->r;
		}
	else if (fm.first->r == NULL)
		if (fm.second != NULL)
			if (fm.second->l == fm.first) fm.second->l = fm.first->l;
			else
			{
				fm.second->r = fm.first->l;
			}
		else
		{
			Tree = fm.first->l;
		}
	else
	{
		Node* per_temp=fm.first;
		Node* temp = fm.first->r;
		while (temp->l != NULL) {
			per_temp = temp;
			temp = temp->l;
		}
		if (per_temp == fm.first) {
			fm.first->r = temp->r;
		}
		else
		{
			per_temp->l = temp->r;

		}
		temp->r = fm.first->r;
		temp->l = fm.first->l;
		if (fm.second != NULL) {
			if (fm.first == fm.second->l) {
				fm.second->l = temp;
			}
			else
			{
				fm.second->r = temp;
			}
		}
		else
		{
			Tree = temp;
		}
	}
	delete fm.first;
	return;

}

void obr_obh(Node *&Tree) {
	if (Tree != NULL) {
		int a, b;
		obr_obh(Tree->l);
		obr_obh(Tree->r);
		if (Tree->l) a = Tree->l->h; else a = -1;
		if (Tree->r) b = Tree->r->h; else b = -1;
		Tree->h = max(a, b) + 1;

		if (Tree->l) a = Tree->l->kol; else a = 0;
		if (Tree->r) b = Tree->r->kol; else b = 0;
		Tree->kol = a + b + 1;




	}
}

int kol_sred=0, znah=-1;

void obh_culc(int h, Node *&Tree) {
	if (Tree!=NULL)
	{
		if ((h - Tree->g) == (h / 2))
		{
			int a, b;
			if (Tree->l) a = Tree->l->kol; else a = 0;
			if (Tree->r) b = Tree->r->kol; else b = 0;
			
			if (a > b) {
				kol_sred++;
			}
		}
		obh_culc(h, Tree->l);
		obh_culc(h, Tree->r);
	}
}

void obh_vnut(int h, Node *&Tree) {
	if (Tree != NULL)
	{
		obh_vnut(h, Tree->l);
		if ((h - Tree->g) == (h / 2))
		{
			int a, b;
			if (Tree->l) a = Tree->l->kol; else a = 0;
			if (Tree->r) b = Tree->r->kol; else b = 0;

			if (a > b) {
				znah++;
				if (znah == kol_sred / 2) {
					del(KOREN, Tree->x);
					return;
				}
			}
		}
		
		obh_vnut(h, Tree->r);
	}
}

int main()
{
	

	//setlocale(LC_ALL, "russian");
	ifstream fin("in.txt"); 
	ofstream fout("out.txt");
	long long i;
	while (fin) {
		fin>>i;
		add_node(i, KOREN);
	}
	obr_obh(KOREN);
	obh_culc(KOREN->h, KOREN);
	if (kol_sred % 2 == 1) obh_vnut(KOREN->h, KOREN);
	lev_obh(KOREN, fout);
	//fout << sum;
	fout.close();
	fin.close();
	//cout<<sum;
	//cin >> sum;
}