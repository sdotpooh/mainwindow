#include<iostream>
#include<iomanip> //width()
using namespace std;
#define width_unit 5

#ifndef Tree_H
#define Tree_H
class Tree
{
    private:
        class Node
        {
            public:
                double avg;
                Node *left, *right;
				//QImage image; 
				//Store the image in the tree
				//Use the find to return the image handle
                Node(double d = 0) //constructor
                    :avg(d), left(NULL), right(NULL) {}
        };
 
        Node *root;
        Node * trav(double, Node * &);
        void chop(Node * N);
        void copy(Node * N);
        void print(ostream &, Node *, int) const;
        void print(Node *, int) const;
 
    public:
        Tree(void); //constructor
        ~Tree(void); //destructor
        double find(double);
        void insert(double);
        void remove(double);
        bool empty(void) const;
        Tree(const Tree &); //copy constructor
        const Tree & operator=(const Tree &); //assignment operator overload
        friend ostream & operator<<(ostream &, const Tree &);
};
#endif //Tree_H
