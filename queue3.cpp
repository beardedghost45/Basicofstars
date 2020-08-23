//Linked  list
// how to reverse a linked lis
 #include<bits/stdc++.h>
using namespace std;

#define N 10
int queu[N];
int front=-1;
int rear=-1;

void enqueue(int x)
{
if(rear==N-1)
cout<<"overflow";
else if(front==-1 &&rear==-1 )
{
	front =rear=0;
	queu[rear]=x;
	}	
else
{
	rear++;
	queu[rear]=x;
}

}

void dequeue()
{
	if(front==-1&& rear==-1)
	cout<<"emtry";
	else if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		cout<<queu[front]<<endl;
		front++;
	}
}
void display()
{
	if(front==-1&& rear==-1)
	cout<<"emtry";
	else{
	
	for(int i=front ;i<=rear;i++)
	cout<<queu[i]<<",";
}
}
void peek()
{
	if(front==-1&& rear==-1)
	cout<<"empty";
	else
	{
		cout<<queu[front]<<endl;
	
	}
}
 
 int main()
 {
 	int n;
 	cin>>n;
 	int m;
 	for(int i=0;i<n;i++)
 	{
 		cin>>m;
 		enqueue(m);
 		
	 }
	 cout<<"-----------------------------------------------------"<<endl;
	 display();
	 cout<<"-----------------------------------------------------"<<endl; 
	dequeue();
	 cout<<"-----------------------------------------------------"<<endl;
	 display();
	 cout<<"-----------------------------------------------------"<<endl;
	 peek();
 }
