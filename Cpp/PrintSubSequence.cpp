#include<bits/stdc++.h>
using namespace std;

void printSub(string str,int index,string ans,vector<string> &output){
    if(index==str.length()){
    output.push_back(ans);
        return;
    }
    //Include
    printSub(str,index+1,ans+str[index],output);
    //Exclude
    printSub(str,index+1,ans,output);
    }

int main(){
    string str;
    cin>>str;
    string ans="";
    vector<string> output;
    printSub( str,0,ans,output);
    for(auto i:output){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Total Subsequences : "<<output.size();
    return 0;
}
