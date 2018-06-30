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
void printpath_inorder(struct Node* root,vector<int>& arr)
{
	if(root==NULL)
		return;
	arr.push_back(root->data);
	printpath_inorder(root->left,arr);
	if(root->left==NULL && root->right==NULL)
		{
			for(int i=0;i<arr.size();i++)
					{
						cout<<arr[i]<<" ";
					}
			cout<<endl;
		}
	printpath_inorder(root->right,arr);

	arr.pop_back();

}
void printpath_postorder(struct Node* root,vector<int>& arr)
{
	if(root==NULL)
		return;
	arr.push_back(root->data);
	printpath_postorder(root->left,arr);

	printpath_postorder(root->right,arr);
	if(root->left==NULL && root->right==NULL)
	{
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	}
	arr.pop_back();

}

void printpath_preorder(struct Node* root,vector<int>& arr)
{
	if(root==NULL)
		return;
	arr.push_back(root->data);
	if(root->left==NULL && root->right==NULL)
	{
		for(int i=0;i<arr.size();i++)
				{
					cout<<arr[i]<<" ";
				}
		cout<<endl;
	}

	printpath_preorder(root->left,arr);

	printpath_preorder(root->right,arr);

	arr.pop_back();

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
vector<int> arr;
    // printpath(root,arr) ;
printpath_preorder(root,arr) ;
cout<<endl;
printpath_inorder(root,arr) ;
cout<<endl;
printpath_postorder(root,arr) ;
cout<<endl;
    return 0;
}

