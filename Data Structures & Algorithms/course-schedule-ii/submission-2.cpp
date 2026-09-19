class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        vector<int>ans;

        for(auto &i:prerequisites){
            indegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }

        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }

        int finished=0;
        while(!q.empty()){
            int  temp = q.front();
            q.pop();
            finished++;
            ans.push_back(temp);
            for(auto &i:adj[temp]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }

        if(finished==numCourses){
            reverse(ans.begin(),ans.end());
            return ans;
        }

        return {};
    }
};
