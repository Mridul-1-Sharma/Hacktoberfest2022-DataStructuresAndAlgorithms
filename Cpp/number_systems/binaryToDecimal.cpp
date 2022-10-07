#include <bits/stdc++.h>
using namespace std;
int binaryToDecimal(int n){
    int ans=0,x=1;
    while(n>0){
        int y=n%10;
        ans=ans+x*y;
        x*=2;
        n/=10;
    }
    return ans;
}
int main(){
    int n=0;
    cin>>n;
    cout<<binaryToDecimal(n)<<endl;
    return 0;
}