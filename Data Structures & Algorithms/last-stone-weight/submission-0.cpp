class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(auto &i:stones){
            pq.push(i);
        }

        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();

            int res = x-y;
            if(res){
                pq.push(res);
            }
        }
        return pq.top();
    }
};
