//============================================================================
// Name        : level.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
using namespace std ;
#include <bits/stdc++.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data ;
    struct Node * left, * right ;
};

struct Node * newNode(int data)
{
    struct Node * node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
void inorder(struct Node* root,stack<Node*>& s)
{

	while(1){

	while(root!=NULL)
	{
		s.push(root);
		root=root->left;

	}

	//cout<<x->data;
	Node* x=s.top();
//cout<<x->data;
	while(x->right==NULL )
	{
		cout<<x->data<<" ";
			s.pop();
			if(!s.empty())
			 x=s.top();
			else
				break;
		//x=x->right;
	}
	if(s.empty())
		{

			break;
		}
	s.pop();
	cout<<x->data<<" ";
	root=x->right;
	}

}
int main()
{
    struct Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
   root->left->left  = newNode(4);
   root->left->right = newNode(5);
   root->right->right = newNode(8);
  root->right->right->left  = newNode(6);
   root->right->right->right  = newNode(7);

    /*   Constructed Binary tree is:
                 1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7    */
    //cout << "Maximum level sum is "
stack<Node*> s;
inorder(root,s);

    return 0;
}

