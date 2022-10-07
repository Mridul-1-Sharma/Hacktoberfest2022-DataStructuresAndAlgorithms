#include<iostream>
#include<vector>
using namespace std;

void duplicatenumber (vector<int>v){
    int i,j;
    for ( i = 0; i <v.size(); i++)
    {
        for ( j =i+1; j<v.size(); j++)
        {
            if (v[i]==v[j])
            {
              cout<<v[i]<<" ";
            }
            
        }
        
    }
    
}
int main(){
    vector<int>v={1,1,2,2,3,4,5,6,};
    duplicatenumber(v);
}
