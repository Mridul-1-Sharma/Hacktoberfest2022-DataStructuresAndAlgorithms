#include <bits/stdc++.h>
using namespace std;
int decimalToBinary(int n){
    int ans=0,x=1;
    while(x<=n){
        x=x*2;
    }
    x/=2;
    while(x>0){
        int lastdigit=n/x;
        n=n-(lastdigit*x);
        x/=2;
        ans=ans*10+lastdigit;
    }
    return ans;
}
int main(){
    int n=0;
    cin>>n;
    cout<<decimalToBinary(n)<<endl;
    return 0;
}