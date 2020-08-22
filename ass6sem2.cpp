#include<bits/stdc++.h>
#include<queue>

using namespace std;

int visited[100];

class lis{

	public:
	int m;
	lis * next;

	lis(int x){
		m = x;
		next = NULL;
	}

};

class data{

	public:
	string name;
	int d,m,y;
	int cm;

	data(string n, int d1, int m1, int y1, int cm1){
		name = n;
		d = d1;	
		m = m1;
		y = y1;
		cm = cm1;	
	}

};

lis * arr[100];
data * dat[100];

lis * ins(lis * top, int m){

	lis * p, * n;
	p = top;
	n = new lis(m);

	if(p!=NULL){
		p = n;
		return p;	
	}
	
	while(p->next!=NULL)
		p = p->next;

	p->next = n;
	return top;

}

int main(){

	int n;
	int i;

	string name;
	int d, m, y;
	int cm;

	int maxcm=0, max=0;
	int mincm=100, min=100;

	int link;
	int j;
	string a, b;
	int u, v;
        
	int month;

	cout<<"Enter total no of friends : ";
	cin>>n;

	for(i=0;i<n;i++){

	cout<<"For "<<i+1<<" friend enter name, dob(date, month, year) and no of comments : \n";
	cin>>name>>d>>m>>y>>cm;
	
		dat[i] = new data(name, d, m, y, cm);

		if(cm>maxcm){
			maxcm = cm;
			max = i;
		}

		if(cm<mincm){
			mincm = cm;
			min = i;
		}

	}

	cout<<"Enter the total no of links : ";
	cin>>link;
	cout<<"\n";

	for(j=0;j<link;j++){

		cout<<"Enter the friends pairs :\n";
		cin>>a>>b;
		cout<<"\n";

		for(i=0;i<n;i++){
	
			if(dat[i]->name==a)
				u = i;

			if(dat[i]->name==b)
				v = i;
			
		}

		arr[u] = ins(arr[u],v);
		arr[v] = ins(arr[v],u);

	}

	queue <int> q;
	q.push(0);

	int t;
	int ch = 0;
	int cnt;
	int ind;

        while(!q.empty()){

		t = q.front();
		q.pop();
		lis * p = arr[t];
		visited[t] = 1;

		cnt = 0;
		while(p!=NULL){
			cnt++;
			if(arr[p->m]==0)
				visited[p->m] = 1;
			p=p->next;	
		}
		
		if(cnt>ch){
			ch = cnt;
			ind = t;
		}

	}

	cout<<"Maximum no of friends are of "<<dat[ind]->name<<" i.e. "<<ch<<"\n";
	cout<<"Maximum no of comments are of "<<dat[max]->name<<" i.e. "<<maxcm<<"\n";
	cout<<"Minimum no of comments are of "<<dat[min]->name<<" i.e. "<<mincm<<"\n";

	cout<<"Enter the month : ";
	cin>>month;
	cout<<"\n";

	cout<<"People having Bday : \n";
	for(i=0;i<n;i++){
		if(dat[i]->m==month)
			cout<<dat[i]->name<<"\n";
	}
	
 
return 0;
}

