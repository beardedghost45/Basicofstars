#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node*left;
	struct  node*right;
};


class Tree
{
	public:struct node *root;

		   Tree()
	       {
	       		root=NULL;
	       }

	       node* insert(node *root)
	       {
	       		int ch;

	       		struct node *ptr;
	       		ptr=new struct node;
	       		ptr->left=NULL;
	       		ptr->right=NULL;
	       		ptr->data=0;

	       		cout<<"Enter node value:";
	       		cin>>ch;

	            ptr->data=ch;

	       		if(root==NULL)
	       		{
	       			root=ptr;
	       		}


      			cout<<"Want to insert into Left node(1 for yes/0 for null):";
     			cin>>ch;
       			if(ch==1)
       			{
       				root->left=insert(root->left);
       			}
       			cout<<"Want to insert into Right node(1 for yes/0 for null):";
       			cin>>ch;
       			if(ch==1)
       			{
       				root->right=insert(root->right);
       			}

	       		return root;
	       }

	       void display(node *root)
	       {
	       		if(root!=NULL)
	       		{
	       			cout<<"::"<<root->data<<"::";
	       			display(root->left);
	       			display(root->right);
	       		}
	       }

	    
        

};

int main()
{
	Tree t;
	struct node*t1, *t2;
	t2=t.insert(t1);
	t.display(t2);
	cout<<"star";
}
