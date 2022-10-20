#include <iostream>
#include<cmath>
using namespace std;
#define Fo(i,n) for(int i=0;i<n;i++)

/*
Problem link: https://www.codechef.com/DEC20B/problems/VACCINE2
*/

void solve()
{
    int n,d;
     cin>>n>>d;
    double e=0,ne=0;
    int x[n];
    Fo(i,n){
        int W;
        cin>>W;
    x[i]=W;
    
    if(W>=80||W<=9)
    e++;
    else
    ne++;
    }
    double x1=e/(double)d;
    double y=ne/(double)d;
    cout<<(ceil(x1)+ceil(y))<<"\n";
    
    
}
int main() {
    int t;
    cin>>t;
    while(t--)
    solve();
	return 0;
}
