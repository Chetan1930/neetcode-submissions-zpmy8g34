class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {


        priority_queue<pair<int,int>>dq;
        vector<int>res;


        for(int i=0;i<nums.size();i++){

            while(!dq.empty() && nums[dq.top().second]<nums[i]){
                dq.pop();
            }

            
            while(!dq.empty() && (i-dq.top().second)>=k){
                dq.pop();
            }


            dq.push({nums[i],i});


            if(i>=(k-1)){
                res.push_back(dq.top().first);
            }
        }


        return res;



       
    }
};
