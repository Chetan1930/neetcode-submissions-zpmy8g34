class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {

        vector<pair<int,string>>target= mp[key];

        int l=0;int r=target.size()-1;

        int ans=-1;
        while(l<=r){
            int mid=(r-l)/2 + l;

            if(target[mid].first==timestamp){
                ans=mid;
                break;
            }
            else if(target[mid].first<timestamp){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;            
        }
      

        
        if(ans==-1)return "";

        return target[ans].second;


    }
};
