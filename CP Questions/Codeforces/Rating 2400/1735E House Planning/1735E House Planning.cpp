// Problem name: House Planning
// Problem link: https://codeforces.com/contest/1735/problem/E

#include<bits/stdc++.h>
using namespace std;
int main(){
 int t;
 cin>>t;
 while(t--){
  int n;
cin>>n;
int l1=1;
int l2=(n-4)/3;
if(((n-4)%3)==2){
  l2=l2+1;
}
int l3=n-4-l2;
int a=abs(l2-l1);
int b=abs(l3-l2);
int c =abs(l3-l1);
int d=min(a,b);
int e=min(d,c);
cout<<e<<endl;
 
  }
  }