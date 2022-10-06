#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void solve(vector<int> pre, int l, int h, int &i){
    
    if(i >= pre.size() or pre[i] < l or pre[i] > h)
        return;

    int val = pre[i++];
    solve(pre, l, val, i);
    solve(pre, val, h, i);
}

bool canRepresentBST(vector<int> pre){

    int i = 0;

    solve(pre, INT_MIN, INT_MAX, i);

    if(i >= pre.size())
        return true;

    return false;
}   

int main(void){

    vector<int> pre{40, 30, 35, 80, 100};

    cout << canRepresentBST(pre) << endl;

    pre = {40, 30, 35, 20, 80, 100};

    cout << canRepresentBST(pre) << endl;

    return 0;
}