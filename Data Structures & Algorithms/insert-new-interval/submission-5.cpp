class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& v1) {
        int n=v.size(),i=0;
        int a=v1[0], b=v1[1];
        vector<vector<int>>res;

        while(i<n && v[i][1]<a){
            res.push_back(v[i]);
            i++;
        }

        while(i<n && v[i][0]<=b){
            a=min(a,v[i][0]);
            b=max(b,v[i][1]);
            i++;
        }

        res.push_back({a,b});


        while(i<n){
            res.push_back(v[i]);
            i++;
        }


        return res;
    
    }
};
