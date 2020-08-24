#include<bits/stdc++.h>
using namespace std;




void display(int a[], int n)
{
   
    for(int i=0;i<n;i++)
    cout<<a[i]<<", ";
}


void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

int main()
{
    int n;
    cin>>n;
    int a[n];
	
	for(int i=0;i<n;i++)
	cin>>a[i];
	insertionSort(a,n);
	display( a, n);

}
