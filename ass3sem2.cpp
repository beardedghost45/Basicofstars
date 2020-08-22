#include<iostream>
#include<queue>
using namespace std;

typedef struct stack_node
{
    struct node* point;
     stack_node* next;
};

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
};

class Stack
{
    struct stack_node *top;

    public:Stack()
           {
              top=NULL;
           }

           void push(struct node *ptr)
           {
              struct stack_node *n;
              n=new struct stack_node;
              n->point=ptr;
              n->next=NULL;

              if(top==NULL)
                  top=n;
              else
              {
                  n->next=top;
                  top=n;
              }
           }

           void pop()
           {
               struct stack_node *p;
               p=top;
               top=top->next;
               delete(p);
           }

           stack_node* emp()
           {
                return top;
           }
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


      			cout<<"Want to insert into Left node(1 for yes/0 for no):";
     			cin>>ch;
       			if(ch==1)
       			{
       				root->left=insert(root->left);
       			}
       			cout<<"Want to insert into Right node(1 for yes/0 for no):";
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
	       			cout<<"->"<<root->data<<"->";
	       			display(root->left);
	       			display(root->right);
	       		}
	       }

	       void display_leaf(node *root)
	       {
	       		Stack s;
	       		struct stack_node *ptr;

                while(root!=NULL)
	       		{
	       			s.push(root);
	       			root=root->left;
	       		}

	       		while(s.emp())
	       		{
	       			ptr=s.emp();
	       			root=ptr->point;
	       			s.pop();

	       			if(root->right==NULL && root->left==NULL)
	       				cout<<"->"<<root->data<<"->";
	       			else
	       			{
	       				root=root->right;

	       				while(root!=NULL)
	       				{
	       					s.push(root);
	       					root=root->left;
	       				}
	       			}
	       		}
	       }
	       void  copy_tree(node *root)
	       {
               struct node *ne;
               ne=root;
               display(ne);
           }
           
			node *mirror(struct node* ptr)  { 
   				 if (ptr== NULL)  
      			 	 return NULL;  
   				 else{ 
        struct node* temp = new struct node; 
    	
    	temp->data = ptr->data;
        temp->left = mirror(ptr->right);
         temp->right = mirror(ptr->left); 
		
		return temp; 
  
         
    } 
} 
           void height(node *root)
           
           {
               int level=0;
               queue<struct node*> c;
               if(root->left==NULL && root->right==NULL)
                    cout<<"0";
               else
               {
                   c.push(root);
                   c.push(NULL);

                   while(!c.empty())
                   {
                       root=c.front();
                       c.pop();

                       if(root==NULL)
                       {
                            if(!c.empty())
                                c.push(NULL);
                            level++;
                       }
                       else
                       {
                           if(root->left)
                                c.push(root->left);
                           if(root->right)
                                c.push(root->right);
                       }
                   }
               }
                cout<<level-1;
           }
};

int main()
{
	Tree t;

	t.root=t.insert(t.root);
	cout<<"\n\n";
	t.display(t.root);

    cout<<"\n";
	cout<<"\nLeaf nodes of tree:\n";
	t.display_leaf(t.root);

	cout<<"\n";
	cout<<"\nMIRROR OF TREE IS:\n";
	struct 
	node *t1 = t.mirror(t.root);
	t.display(t1);

	cout<<"\n";
	cout<<"\nHEIGHT OF TREE IS:\n";
	t.height(t.root);

    return 0;
}
