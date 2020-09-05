#include<bits/stdc++.h>
using namespace std;

//BFS for bst!
struct node 
{ 
	int data; 
	struct node* left, *right; 
}; 

int height(struct node* node) 
{ 
	if (node==NULL) 
		return 0; 
	else
	{ 
	
		int lheight = height(node->left); 
		int rheight = height(node->right); 

		/* use the larger one */
		if (lheight > rheight) 
			return(lheight+1); 
		else return(rheight+1); 
	} 
}

void printGivenLevel(struct node* root, int level) 
{ 
	if (root == NULL) 
		return; 
	if (level == 1) 
		cout<< root->data; 
	else if (level > 1) 
	{ 
		printGivenLevel(root->left, level-1); 
		printGivenLevel(root->right, level-1); 
	} 
} 

struct node* newNode(int data); 


void printLevelOrder(struct node* root) 
{ 
	int h = height(root); 
	int i; 
	for (i=1; i<=h; i++) 
		printGivenLevel(root, i); 
} 




struct node* newNode(int data) 
{ 
	struct node* node = (struct node*) 
						malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return(node); 
} 

int main() 
{ 
	struct node *root = newNode(1); 
	root->left	 = newNode(2); 
	root->right	 = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 

	cout<<"Level Order traversal of binary tree is \n"; 
	printLevelOrder(root); 

	return 0; 
} 

