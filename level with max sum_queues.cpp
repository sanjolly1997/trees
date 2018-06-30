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

int maxLevelSum(struct Node* root)
{

   queue<Node*>q;
   q.push(root);

   int sum=0;
   int max=INT_MIN;
   while(!q.empty())
   {
	   int count=q.size();
	   //cout<<count;
	   for(int i=0;i<count;i++)
	   {
		   struct Node* element=q.front();
		   q.pop();
		   sum=sum+element->data;
		   if(element->left!=NULL)
			   q.push(element->left);
		   if(element->right!=NULL)
		   	   q.push(element->right);
		   //cout<<sum;
	   }
	   if(sum>max)
		   max=sum;
	   sum=0;

   }
   return max;

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
    int x=     maxLevelSum(root) ;
    cout<<x;
    return 0;
}

