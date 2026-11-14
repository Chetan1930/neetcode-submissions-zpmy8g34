class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>>res;

        sort(v.begin(),v.end());

        int a=v[0][0];
        int b=v[0][1];

        for(int i=1;i<n;i++){

            if(v[i][0]<=b){
                a=min(a,v[i][0]);
                b=max(b,v[i][1]);
            }
            else{
                res.push_back({a,b});
                a=v[i][0];
                b=v[i][1];
            }
        }
        res.push_back({a,b});


        return res;
        
    }
};
