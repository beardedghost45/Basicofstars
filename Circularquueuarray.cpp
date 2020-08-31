#include<bits/stdc++.h>
using namespace std;


#define N 5
int que[N];
int front=-1;
int rear=-1;

void enqu(int x)
{
	if(front==-1)
	{
		front=rear=0;
		que[rear]=x;
	}
	else if((rear+1)%N==front)
	{
		cout<<"OVERFLOW";
		
	}
	else
	{
		rear=(rear+1)%N;
		que[rear]=x;
	}
}

void deq()
{
	if(front==-1)
	cout<<"emty";
	else if(front==rear)
	{
		front==-1;
		rear=-1;
		
	}
	else
	{
		cout<<"ELEMNT IS "<<que[front]<<endl;
		front=(front+1)%N;
	}
}


void display()
{
    int j=front;
	if(front==-1&& rear==-1)
	cout<<"E<PTY"<<endl;
	else{
	cout<<"Queu is"<<endl;
	while(j!=rear)
	{
		cout<<que[j]<<",";
		j=(j+1)%N;
	}
	cout<<que[rear];
}

cout<<endl;
}


int  main()
{
	enqu(2);
	enqu(4);
	enqu(6);
	enqu(7);
	enqu(10);
	display();
	cout<<"--------------------------------------------------"<<endl;
	deq();
	deq();
	cout<<"--------------------------------------------------"<<endl;
	display();
}
