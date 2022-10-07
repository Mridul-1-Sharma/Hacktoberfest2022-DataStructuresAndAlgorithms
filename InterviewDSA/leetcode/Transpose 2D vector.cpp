#include<iostream>
#include<vector>
using namespace std;
int transpose(vector<vector<int>>vec){
    int t,i,j;
    for( int i=0;i<vec.size();i++){
for(int j=0;j<=i;j++){
    t=vec[i][j];
    vec[i][j]=vec[j][i];
    vec[j][i]=t;

}
    }
    for(i=0;i<vec.size();i++){
        for(j=0;j<vec[i].size();j++){
            cout<<vec[i][j];
        }
        cout<<endl;
    }
}
void display(vector<vector<int>>vec){
    int i,j;
    for(i=0;i<vec.size();i++){
        for(j=0;j<vec[i].size();j++){
            cout<<vec[i][j];
        }
        cout<<endl;
    }

}
int main(){
    vector<vector<int>>vec={{1,2,3},{4,5,6},{7,8,9}};
    cout<<"display"<<endl;
    display(vec);
     cout<<"transpose"<<endl;
    
    
    transpose(vec);
}
