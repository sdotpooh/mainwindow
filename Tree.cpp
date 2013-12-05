#include "Tree.h"
#include "Globals.h"
#include <iostream>
using namespace std;

Tree::Tree(void)
{
     root=NULL;
}
 
bool 
Tree::empty(void) const
{
     return !root;
}
 
Tree::Node * 
Tree::trav(double foo, Node * & par)
{
     Node * curr = root;
     par = NULL;
     while(curr && curr->avg != 0)
     {
         par = curr;
		 if(foo <= curr->avg)
             curr = curr->left;
         else
             curr = curr->right;
     }
     return curr;
}
 
string
Tree::find(double foo)
{
	//If there's an exact match return the filename,
	//else find the closest match to the avg and
	//return the filename.
	Node *par = NULL;
    Node * curr = root;
    string closest = " ";
	double closestBy = 10000; 
    while(curr && curr->avg != 0)
    {
        par = curr;
		if (foo == curr->avg)	
			return curr->fileName;
		else if(foo < curr->avg) {
			 if((curr->avg - foo) < closestBy) {
				closest = curr->fileName;
				closestBy = curr->avg - foo;
			 }
             curr = curr->left;
		}
        else {
			if((foo - curr->avg) < closestBy) {
				closest = curr->fileName;
				closestBy = foo - curr->avg;
			}
            curr = curr->right;
		}
    } 
	return closest;
}
 
void 
Tree::insert(double foo, string s)
{
     Node * par = NULL;
     Node * curr = trav(foo, par);
     //Node * curr = root;
	 if(!curr)
     {
         curr = new Node(foo, s);
         if(!par)
             root = curr;
         else if(foo <= par->avg)
             par->left=curr;
         else
             par->right=curr;
     }
}
 
void 
Tree::remove(const double foo)
{
     Node * par=NULL; //parent is null by default
     Node * curr=trav(foo,par); //locate the node of the foo
     if(curr) //if it is not null then
     {
         if(curr->left && curr->right) //2 children case
         {
             Node * tmp=curr;
             par=curr;
             curr=curr->left;
             while(curr->right)
             {
                 par=curr;
                 curr=curr->right;
             }
             tmp->avg=curr->avg;
         }
 
         //1 or 0 child case
         Node *tmp=(curr->left ? curr->left : curr->right);
 
         if(!par)
             root=tmp;
         else if(par->avg < curr->avg)
                  par->right=tmp;
              else
                  par->left=tmp;
         delete curr;
     }
}
 
void 
Tree::chop(Node *N)
{
     if(N)
     {
         chop(N->left);
         chop(N->right);
         delete N;
     }
}
 
//destructor
Tree::~Tree(void)
{
     chop(root);
}

Tree::Tree(const Tree & T)
{
     root=NULL;
     copy(T.root);
}

void 
Tree::copy(Node * N)
{
     if(N)
     {
         insert(N->avg, N->fileName);
         copy(N->left);
         copy(N->right);
     }
}

const Tree & 
Tree::operator=(const Tree & T)
{
     if(this != &T)
     {
          chop(root);
          root=NULL;
          copy(T.root);
     }
     return *this;
}
 
//the recursive tree output
void 
Tree::print(ostream & ost, Node * curr, int level) const
{
     if(curr) //if the current node is not null then
     {
         print(ost,curr->right,level+1); //try to go to right node
         //output the node avg w/ respect to its level
         ost<<setw(level*width_unit)<<curr->avg<<endl;
         print(ost,curr->left,level+1); //try to go to left node
     }
}
 
//the recursive tree print
void 
Tree::print(Node * curr, int level) const
{
     if(curr) //if the current node is not null then
     {
         print(curr->right,level+1); //try to go to right node
         //print the node avg w/ respect to its level
         cout<<setw(level*width_unit)<<curr->avg<<endl;
         print(curr->left,level+1); //try to go to left node
     }
}
 
ostream & operator<<(ostream &ost, const Tree &t)
{
     t.print(ost, t.root, 1);
     return ost;
}
