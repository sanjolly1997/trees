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
int findheight(struct Node* root)
{
	if(root==NULL)
		return -1;
	int lheight=findheight(root->left);
	int rheight=findheight(root->right);
	int height=max(lheight,rheight)+1;
	return height;
}
int count=0;
void findsum(struct Node* root,int h)
{
	if(root==NULL)
		return;
	if(h==0)
	{
		count=count+root->data;
		return;
	}
	findsum(root->left,h-1);
	findsum(root->right,h-1);
}
int maxLevelSum(struct Node* root)
{
	int h=findheight(root);
	int max=0;
	for(int i=0;i<=h;i++)
	{
		findsum(root,i);
		if(count>max)
			max=count;
		count=0;
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
    cout << "Maximum level sum is "
         << maxLevelSum(root) << endl;
    return 0;
}

