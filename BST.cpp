#include<bits/stdc++.h>
using namespace std;

struct node
{
   int data;
   struct node *left;
   struct node *right;
};
struct node*root=NULL;


void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->left = NULL;
   tempNode->right = NULL;

   //if tree is empty, create root node
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent  = root;

      while(current) {
      	
    			parent=current;
	             if(tempNode->data>current->data)   
				   {
				   	current=current->right;
				   }
				else
				{
					current=current->left;
				}
      } 
	  if(tempNode->data>parent->data)
	  {
	  	parent->right=tempNode;
				 }
		else
		{
			parent->left=tempNode;
				   }           
   }
}


void preorder(struct node*root)
{
if(root==NULL)
{
    return;
}
cout<<root->data<<"->";
preorder(root->left);
preorder(root->right);	

	}	


void inorder(struct node*root)
{
if(root==NULL)
{
    return;
}
inorder(root->left);
cout<<root->data<<"->";
inorder(root->right);	
	
}

void postorder(struct node*root)
{
if(root==NULL)
{
    return;
}
postorder(root->left);
postorder(root->right);
cout<<root->data<<"->";	
	
}
 
 int main()
 {
    
int x;
while( cin>>x)
{
    insert(x);
}

cout<<"--------------------------------------------------------"<<endl;
 preorder(root);
 cout<<endl;
cout<<"--------------------------------------------------------"<<endl;
inorder(root);
cout<<endl;
cout<<"--------------------------------------------------------"<<endl;
 postorder(root);
 cout<<endl;
cout<<"--------------------------------------------------------"<<endl;


 }
