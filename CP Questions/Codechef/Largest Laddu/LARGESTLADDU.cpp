#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<long>
#define int long long


// No negative numbers:
/*
Constrains:
1≤T≤ 2*10^4
0≤N≤13
0≤Ai≤109
Sum of |A| over all test cases does not exceed  2⋅105
*/

void solve(){
    int n;
    cin>>n;

    if(n == 0){
        int val;
        cin>>val;
        cout<<"YES\n";
        return ;
    }
   
   int size = pow(2,n);
   vi x(size);

   for(int i =0 ;i<size;i++){
       cin>>x[i];
   }

    if(size ==2){
    sort(x.begin(), x.end());
    if((x[1]- x[0])<=1 ) cout<<"YES\n";
    else cout<<"NO\n";
    return;
    }


    int minElement = *min_element(x.begin(),x.end());
    int maxElement = *max_element(x.begin(),x.end());
    bool ok = maxElement - minElement <=1?true:false;
    if(!ok)
    cout<<"NO\n";
    else
    cout<<"YES\n";

}

signed main(){
    boost;
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}