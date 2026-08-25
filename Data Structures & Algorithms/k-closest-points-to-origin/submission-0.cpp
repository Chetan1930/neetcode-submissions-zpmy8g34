class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,vector<int>>>pq;

        for(auto &i:points){
            float dis=sqrt(pow(i[0],2)+pow(i[1],2));
            pq.push({dis,i});

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<vector<int>>res;

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }


        return res;
    }
};
