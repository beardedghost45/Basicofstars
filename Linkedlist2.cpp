//Linked  list
// how to reverse a linked lis
 #include<bits/stdc++.h>
using namespace std;

 struct Node
{
   int data;
   struct Node *next;
};

Node*top=NULL;

void push(int x)
{
	Node*newnode=(Node*)malloc(sizeof(Node));
	newnode->data=x;
	newnode->next=top;
	top=newnode;
}

void display()
{
	Node*temp=top;
	if(temp==NULL)
	cout<<"EMTY";
	else
	{
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	}
}
	
void peek()
{
	
	if(top==NULL)
	cout<<"emty";
	else
	{
		cout<<top->data<<endl;
		}	
}

void pop()
{
	Node*temp=top;
	if(top==NULL)
	cout<<"UNDERFLOW"<<endl;
	else
	{
		cout<<temp->data<<endl;
		top=temp->next;
	}
	free(temp);
}
 
 
 int main()
 {
 	
 int m;
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 {
 	cin>>m;
 	push(m);
 }
 cout<<"---------------------------------------------"<<endl;
 display();
 cout<<"---------------------------------------------"<<endl;
	peek();
    cout<<"---------------------------------------------"<<endl;
    pop();
cout<<"---------------------------------------------"<<endl;
 display();
 }
