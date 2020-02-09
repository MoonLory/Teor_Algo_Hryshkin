#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;
//long long sum;
struct Node                        
{
	int x;                           
	Node *l, *r;                     
};

void add_node(int x, Node *&MyTree)                  
{
	if (NULL == MyTree)                           
	{
		MyTree = new Node;                          
		MyTree->x = x;                             
		MyTree->l = MyTree->r = NULL;               
	}

	if (x < MyTree->x)               
	{
		if (MyTree->l != NULL) add_node(x, MyTree->l); 
		else                      
		{
			MyTree->l = new Node;                 
			MyTree->l->l = MyTree->l->r = NULL;  
			MyTree->l->x = x;                     
		}
	}

	if (x > MyTree->x)          
	{
		if (MyTree->r != NULL) add_node(x, MyTree->r); 
		else                                          
		{
			MyTree->r = new Node;                 
			MyTree->r->l = MyTree->r->r = NULL;   
			MyTree->r->x = x;                     
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




int main()
{
	Node *Tree = NULL;

	//setlocale(LC_ALL, "russian");
	ifstream fin("input.txt"); 
	ofstream fout("output.txt");
	long long i;
	int a;
	fin >> a;
	while (fin) {
		fin>>i;
		add_node(i, Tree);
	}
	del(Tree, a);
	lev_obh(Tree, fout);
	//fout << sum;
	fout.close();
	fin.close();
	//cout<<sum;
	//cin >> sum;
}