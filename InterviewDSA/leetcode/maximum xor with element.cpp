struct Node{
    Node* arr[2] {NULL};
 
    bool contain(int bit){
        return arr[bit]!=NULL;
    }
    void put(int bit, Node* node){
        arr[bit] = node;
    }
    Node* get(int bit){
        return arr[bit];
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(!node->contain(bit)){
                node->put(bit,new Node);
            }
            node = node->get(bit);
        }
    }
    int getMax(int num){
        int val = 0;
        Node* node = root;
        for(int i = 31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->contain(1-bit)){
                val = val | (1<<i);
                node = node -> get(1-bit);
            }
            else{
                node = node -> get(bit);
            }
        }
        return val;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        vector<pair<int,pair<int,int>>>vec;
        int q = queries.size();
        for(int i = 0; i<q; i++){
            vec.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(vec.begin(),vec.end());
        vector<int>ans(q,0);
        sort(arr.begin(),arr.end());
        Trie trie;
        int n = arr.size(), idx = 0;
        for(int i = 0; i<q; i++){
            int mi = vec[i].first;
            int xi = vec[i].second.first;
            int idxi = vec[i].second.second;
            while(idx<n and arr[idx] <= mi){
                trie.insert(arr[idx]);
                idx++;
            }
            if(idx == 0){
                ans[idxi] = -1;
            }
            else{
                ans[idxi] = trie.getMax(xi);
            }
            
        }
        return ans;
    }
};
