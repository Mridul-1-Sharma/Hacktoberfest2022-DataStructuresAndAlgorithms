#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void printreverse(int a[],int S,int E,int n)
{  
    while(S<E)
    {
      int  temp=a[S];
        a[S]=a[E];
        a[E]=temp;
        S++;
        E--;
    }
    for(int i=0;i<n;i++)
    {     a[i]=n-1-i;
        cout<<a[i]<<" ";
    }
    cout<<endl;

}
void printarray(int a[ ],int n){
    for(int i=0;i<n;i++)
    {     a[i]=i;
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the size of array n =";
    cin>>n;
    int a[n];
    cout<<"Array is :  "<<endl;
     printarray(a,n);
    cout<<"Reverse of array is : "<<endl;
    printreverse(a,0,n-1,n);
    return 0;
}
