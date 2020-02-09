#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;
long long sum;
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

void show(Node *&Tree)              
{
	if (Tree != NULL) {
		sum += Tree->x;
		//cout << (Tree->x) << endl;
		show(Tree->l);
		show(Tree->r);
	}
	
}

int main()
{
	Node *Tree = NULL;

	//setlocale(LC_ALL, "russian");
	ifstream fin("input.txt"); 
	ofstream fout("output.txt");
	long long i;
	while (fin) {
		fin>>i;
		add_node(i, Tree);
	}

	show(Tree);
	fout << sum;
	fout.close();
	fin.close();
	//cout<<sum;
	//cin >> sum;
}