#include<bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   struct Node *next;
};
struct Node*front=NULL;
struct Node*rear=NULL;

void enqu(int x)
{
	struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=x; 
	newnode->next=NULL;
	
	if(front ==0 && rear==0)
	{
	    front=rear=newnode; 
	    rear->next=newnode;
	}
	else 
	{
		rear->next=newnode;
		rear=newnode;
		rear->next=front;
	}
}


void display()
{
	struct Node*temp=front;
	if(front==NULL && rear==NULL)
	cout<<"emty";
	else
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
}

void dequ()
{
	struct Node*temp=front;
	if(front==NULL && rear==NULL)
	cout<<"emty";
	else if(front==rear)
	{
		front=rear=NULL;
		free(temp);
	}
	else
	{
		
		front=front->next;
		cout<<temp->data<<endl;
		rear->next=front;
		free(temp);
	}
}

void peek()
{
	
	if(front==NULL && rear==NULL)
	cout<<"emty";
	else
	cout<<front->data<<endl;
}
 
 int main()
 {
 	
 
 int n;
 cin>>n;
 int m;
for(int i=0;i<n;i++){
cin>>m;
 enqu(m);
}
 cout<<"---------------------------------------------"<<endl;
 display();
 cout<<endl;
 cout<<"---------------------------------------------"<<endl;
 dequ()	;
 cout<<endl;
 cout<<"---------------------------------------------"<<endl;
 display();
 cout<<endl;
 cout<<"---------------------------------------------"<<endl;
 peek();
 cout<<endl;
 cout<<"---------------------------------------------"<<endl;
    
    

 }
