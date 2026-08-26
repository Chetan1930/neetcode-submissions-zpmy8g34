class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans=0;

        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        for(auto &i:tasks){
            mp[i]++;
        }

        for(auto &i:mp){
            pq.push({i.second,i.first});
        }

        while(!pq.empty()){
            
            queue<pair<int,char>>q;

            int j=n+1;
            
            while(j--){
                if(!pq.empty()){
                    pair<int,char> temp = pq.top();
                    pq.pop();
                    temp.first--;
                    if(temp.first > 0)q.push(temp);
                }
                ans++;

                if(pq.empty() && q.empty())ans--;
    
            }
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }



        return ans+1;
        
    }
};
