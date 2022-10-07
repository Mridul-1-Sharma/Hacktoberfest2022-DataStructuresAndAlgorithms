#include <bits/stdc++.h>
using namespace std;
int hexadecimalToDecimal(string n){
    int ans=0,x=1;
    int s=n.size();
    for(int j=s-1;j>=0;j--){
        if(n[j]>='0' && n[j]<='9')
        ans=ans+x*(n[j]-'0');
        else if(n[j]>='A' && n[j]<='F')
        ans=ans+x*((n[j]-'A')+10);
        x=x*16;
    }
    return ans;
}
int main(){
   string n;
    cin>>n;
    cout<<hexadecimalToDecimal(n)<<endl;
    return 0;
}