class Solution {
public:
    void dfs(int k,int time, unordered_map<int,vector<pair<int,int>>>& adj, vector<int>& dis){
        if(time > dis[k])return ;

        dis[k] = time;

        for(auto &i:adj[k]){
            dfs(i.first,time + i.second, adj,dis);
        }


        return ;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto &i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }

        vector<int>dis(n+1,INT_MAX);

        dfs(k,0,adj,dis);
        int maxE = *max_element(dis.begin()+1,dis.end());

        if(maxE==INT_MAX)return -1;

        return maxE;
    }
};
