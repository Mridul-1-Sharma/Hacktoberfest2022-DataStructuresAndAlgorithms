class TimeMap {
public:
    map<string,map<int,string>> k;
    map<string,map<int,string>>g;
    TimeMap() {   
    }
    void set(string key, string value, int timestamp) {
        k[key][timestamp]=value;
    }
    string get(string key, int timestamp) {
        if(k.find(key)!=k.end()){
            if(k[key].find(timestamp)!=k[key].end()){
                g[key][timestamp]=k[key][timestamp];
                return k[key][timestamp];
            }else {
               if(k[key].rbegin()->first<=timestamp)return k[key].rbegin()->second;
                else if(g[key].size()==0)return "";
                else return g[key].rbegin()->second;
            }
        }else return "";
    }
};
