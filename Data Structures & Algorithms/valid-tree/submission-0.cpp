class Solution {
public:

    bool dfs(int node , int parent ,vector<vector<int>>& adj, unordered_set<int> & s ){ 

        if(s.find(parent)!=s.end())return false;
        s.insert(parent);

        for(auto &i:adj[node]){
            if(i==parent)continue ;

            return dfs(i,node,adj,s);
        }


        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1)return false;

        vector<vector<int>>adj(n);

        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        unordered_set<int>s;


        if(!dfs(0,-1,adj,s))return false;

        return true;


    }
};
